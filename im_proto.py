import numpy as np
import cv2

prev_x = 0
prev_y = 0


def distance(event, x, y, flags, param):
	"""
	callback function for cv2.setMouseCallback()
	computes euclidean distance between clicked point and previous point
	note that distance is pixels here (should use px-2-m scale irl)
	"""

	# TODO any way to not use globals?
	global mouse_x, mouse_y, prev_x, prev_y
	
	if event == cv2.EVENT_LBUTTONDBLCLK:
		mouse_x = x
		mouse_y = y
		distance = np.sqrt((mouse_x - prev_x) ** 2 + (mouse_y - prev_y) ** 2)
		print(f"current: ({mouse_x}, {mouse_y}), prev: ({prev_x}, {prev_y}), distance = {distance}")
		prev_x = mouse_x
		prev_y = mouse_y


def main():
	path = "im.jpg"
	img = cv2.imread(path)

	cv2.namedWindow("window")
	params = "urmom"
	cv2.setMouseCallback("window", distance, params)

	cv2.imshow("window", img)
	key = cv2.waitKey(0)  # press 0 to destroy window or see below

	if key == ord('s'):
		cv2.destroyWindow("window")


if __name__ == "__main__":
	main()

