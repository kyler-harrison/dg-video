def get_box(frame, upper_left, bottom_right):
	"""
	from given frame and two corners, get matrix of all points bounded 
	assumes upper_left.x < bottom_right.x and upper_left.y < bottom_right.y

	frame: np array of video frame (y, x, r, g, b)
	upper_left: upper left point of box (x, y)
	bottom_right: bottom right point of box (x, y)

	returns tensor of rgb vals of all points in box
	"""

	return frame[upper_left[1]:bottom_right[1], upper_left[0]:bottom_right[0]]


def compute_box_scores(frame, target_box):
	"""
	given a frame and target_box, iterate the target_box over the frame and compute rgb difference

	frame: video frame (np array)
	target_box: np array of rgb values of original detection box (from get_box())

	returns box (computed from get_box()) of the least different box in frame
	"""
	pass

