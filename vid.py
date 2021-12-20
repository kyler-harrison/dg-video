import cv2
import numpy as np


fps = 30  # TODO actually get
time_per_frame = 1 / fps

scale_points = []  # used to track two scale points (first two clicked)
scale = 0  # will be set to px/m
scale_amount = 0.283  # how many m is the px scale equivalent to 

points = []  # stores all clicked points (after scale points)
len_points = 0  # track length of points (MAX SPEED and EFFICIENCY BRO)
speeds = []  # stores speeds of each subsequent click (idx 0 is the speed between idx 0 and 1 of points)
len_speeds = 0
mean_speed = 0  # ovr mean speed

scale_uncertainty = 20  # +- px
point_uncertainty = 10  # +- px
speed_uncertainty = point_uncertainty / scale_uncertainty  # prop. uncertainties through and it's this many +- m/s


def euc_distance(point0, point1):
	"""
	returns euclidean distance between two 2d points 
	point0, point1: tuples of (x, y)
	"""

	return np.sqrt((point0[0] - point1[0]) ** 2 + (point0[1]- point1[1]) ** 2)


def compute_speed():
	"""
	computes speed between last two point tuples in points (if possible) and overall mean speed
	assumes each point in points came from a unique frame and is in sequential order (should change later)
	also assumes each point is frame to frame (no skipped frames - again, change this later (not hard))
	"""

	global points
	global len_points
	global mean_speed
	global speeds
	global len_speeds
	global time_per_frame
	global scale
	
	# can only compute speed if at least two points exist
	if len_points > 1:
		speed = (euc_distance(points[-1], points[-2]) / scale) / time_per_frame
		speeds.append(speed)
		len_speeds += 1

		# can only compute mean speed if more than 1 speed calculation has been made
		if len_speeds > 1:
			mean_speed = (mean_speed + speed) / 2
		else:
			mean_speed = speed

		print(f"speed between last two points = {speed:.3f} +- {speed_uncertainty:.3f} m/s, mean speed = {mean_speed:.3f} +- {speed_uncertainty:.3f} m/s")


def handle_click(event, x, y, flags, param):
	"""
	callback function for cv2.setMouseCallback()
	adds (x, y) to global points, or sets scale
	"""

	# TODO any way to not use globals?
	global points 
	global len_points
	global scale_points
	global scale
	
	if event == cv2.EVENT_LBUTTONDBLCLK:
		if scale > 0:
			points.append((x, y))
			len_points += 1
			compute_speed()

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

	path = "test_vid_0.MOV"
	cap = cv2.VideoCapture(path)
	cv2.namedWindow("window")
	cv2.setMouseCallback("window", handle_click)
	frame_idx = 0

	while True:
		#print("i ran")
		ret, frame = cap.read()
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

