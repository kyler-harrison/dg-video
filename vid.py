import cv2
import numpy as np
from detection import get_box, compute_box_scores


fps = 30  # TODO actually get
time_per_frame = 1 / fps

num_clicks = 0
release_box_points = []  # holds 4 points of the release box
release_box = None

# TODO rm after done testing detection
next_box_points = []
next_box = None

scale_points = []  # used to track two scale points (first two clicked)
scale = 0  # will be set to px/m
scale_amount = 0.283  # how many m is the px scale equivalent to 

points = []  # stores all clicked points (after scale points)
len_points = 0  # track length of points (MAX SPEED and EFFICIENCY BRO)

speeds = []  # stores speeds of each subsequent click (idx 0 is the speed between idx 0 and 1 of points)
speeds_x = []
speeds_y = []
len_speeds = 0
mean_speed = 0  # ovr mean speed
mean_speed_x = 0
mean_speed_y = 0

scale_uncertainty = 20  # +- px
point_uncertainty = 10  # +- px
speed_uncertainty = point_uncertainty / scale_uncertainty  # prop. uncertainties through and it's this many +- m/s


def euc_distance(point0, point1):
	"""
	returns euclidean distance between two 2d points 
	point0, point1: tuples of (x, y)
	"""

	return np.sqrt((point0[0] - point1[0]) ** 2 + (point0[1]- point1[1]) ** 2)


def ms_2_mph(speed):
	"""
	compute mph from m/s
	speed: speed in m/s
	returns speed in mph
	"""

	return speed * 2.23694


def compute_speed():
	"""
	computes speed between last two point tuples in points (if possible) and overall mean speed
	assumes each point in points came from a unique frame and is in sequential order (should change later)
	also assumes each point is frame to frame (no skipped frames - again, change this later (not hard - just track frame idx))
	"""

	global points
	global len_points
	global mean_speed
	global mean_speed_x
	global mean_speed_y
	global speeds
	global len_speeds
	global speeds_x
	global speeds_y
	global time_per_frame
	global scale

	
	# can only compute speed if at least two points exist
	if len_points > 1:
		# NOTE computing component speeds makes euc_distance() redundant
		speed_x = abs(points[-1][0] - points[-2][0]) / scale / time_per_frame
		speed_y = abs(points[-1][1] - points[-2][1]) / scale / time_per_frame
		speed = (euc_distance(points[-1], points[-2]) / scale) / time_per_frame
		speeds.append(speed)
		len_speeds += 1

		# can only compute mean speed if more than 1 speed calculation has been made
		if len_speeds > 1:
			mean_speed = (mean_speed + speed) / 2
			mean_speed_x = (mean_speed_x + speed_x) / 2
			mean_speed_y = (mean_speed_y + speed_y) / 2
		else:
			mean_speed = speed
			mean_speed_x = speed_x
			mean_speed_y = speed_y

		# NOTE the inefficiency
		print(f"\nspeed between last two points = {speed:.3f} +- {speed_uncertainty:.3f} m/s ({ms_2_mph(speed):.3f} +- {ms_2_mph(speed_uncertainty):.3f} mph)")
		print(f"speed = [{speed_x:.3f}, {speed_y:.3f}] m/s ([{ms_2_mph(speed_x):.3f}, {ms_2_mph(speed_y):.3f}] mph)")
		print(f"ovr. mean speed = {mean_speed:.3f} +- {speed_uncertainty:.3f} m/s ({ms_2_mph(mean_speed):.3f} +- {ms_2_mph(speed_uncertainty):.3f} mph)")
		print(f"mean speed = [{mean_speed_x:.3f}, {mean_speed_y:.3f}] +- {speed_uncertainty:.3f} m/s ([{ms_2_mph(mean_speed_x):.3f}, {ms_2_mph(mean_speed_y):.3f}] mph)")


def handle_click(event, x, y, flags, param):
	"""
	callback function for cv2.setMouseCallback()
	adds (x, y) to global points, or sets scale
	"""

	# TODO any way to not use globals?
	global num_clicks
	global points 
	global len_points
	global scale_points
	global scale
	global release_box_points
	global release_box
	global next_box_points
	global next_box
	
	if event == cv2.EVENT_LBUTTONDBLCLK:
		num_clicks += 1
		print(f"(x,y) = ({x}, {y}), num_clicks = {num_clicks}")

		# after scale and disc release box
		if num_clicks > 4:
			"""
			points.append((x, y))
			len_points += 1
			compute_speed()
			"""

			next_box_points.append([x, y])

			if num_clicks % 2 == 0:
				next_box_points[1][1] = next_box_points[0][1] + release_box.shape[0]
				next_box_points[1][0] = next_box_points[0][0] + release_box.shape[1]

				next_box = get_box(param["frame"], next_box_points[0], next_box_points[1])
				diff_sum = np.sum(np.abs(next_box - release_box))
				print(f"diff_sum = {diff_sum}")
				next_box_points = []

			compute_box_scores(param["frame"], release_box)

		# click for disc release box
		elif 2 < num_clicks <= 4:
			release_box_points.append((x, y))

			if num_clicks == 4:
				#print(param["frame"][:10])
				#print(release_box_points[0])
				release_box = get_box(param["frame"], release_box_points[0], release_box_points[1])
				#b = frame[release_box_points[0][1]:release_box_points[1][1], release_box_points[0][0]:release_box_points[1][0]]
				print(f"release_box_points = {release_box_points}")
				print(f"release_box.shape = {release_box.shape}")

		# set scale
		else:
			scale_points.append((x, y))
			
			# scale is made from first two points clicked
			if len(scale_points) == 2:  
				scale = euc_distance(scale_points[0], scale_points[1]) / scale_amount
				print(f"scale set to {scale} px/m")

	return


def main():
	# load frames. compute num frames, time, fps.
	# iterate through frames, imshow on each frame on left/right arrow keys.
	# actually draw circles, compute distance between points of frames
	# compute speed (average each subsequent speed calc? other methdo?)

	print("first 2 clicks: set scale\nnext 2 clicks: release bounding box (top left, bottom right)\nnext clicks: center position of disc in subsequent frames")
	path = "fc_1.MOV"
	cap = cv2.VideoCapture(path)
	cv2.namedWindow("window")
	frame_idx = 0

	while True:
		#print("i ran")
		ret, frame = cap.read()
		param = {"frame": frame}  # TODO can i do this?
		cv2.setMouseCallback("window", handle_click, param)
		cv2.imshow("window", frame)

		key = cv2.waitKeyEx(0)  # press 0 to destroy window or see below
		#print(key)

		# left: 65361, right: 65363  (aren't detected when used with mouse callback but other keys are?)
		if key == ord('q'):
			break

		elif key == ord('a'):  # left arrow
			#print("left clicked")
			frame_idx -= 1  # TODO err handles
			cap.set(cv2.CAP_PROP_POS_FRAMES, frame_idx)

		elif key == ord('d'):  # right arrow
			#print("right clicked")
			frame_idx += 1  # TODO err handles
			cap.set(cv2.CAP_PROP_POS_FRAMES, frame_idx)

	cv2.destroyAllWindows()


if __name__ == "__main__":
	main()

