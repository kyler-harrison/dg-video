import numpy as np


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
	NOTE this only appears to work when disc is a color that is distinct from background, and the initial
	bounding box is very small (like <= 10px x 10px), seems too messy to work otherwise

	frame: video frame (np array)
	target_box: np array of rgb values of original detection box (from get_box())

	returns upper_left and bottom_right points of best box
	"""

	box_shape = target_box.shape
	row_shift = box_shape[0]
	col_shift = box_shape[1]
	print(f"box_shape = {target_box.shape}, row_shift = {row_shift}, col_shift = {col_shift}")

	frame_shape = frame.shape

	num_row_shifts = frame_shape[0] // row_shift
	num_col_shifts = frame_shape[1] // col_shift 

	row_start = 0
	row_end = row_start + row_shift

	diffs = []

	for row_idx in range(num_row_shifts):
		col_start = 0
		col_end = col_start + col_shift
		
		for col_idx in range(num_col_shifts):
			#print(f"done: row_idx = {row_idx}, col_idx = {col_idx}")
			diffs.append((np.sum(np.abs(target_box - frame[row_start:row_end, col_start:col_end])), (col_start, row_start), (col_end, row_end)))
			col_start = col_end
			col_end += col_shift

		row_start = row_end
		row_end += row_shift
	
	# TODO change

	diffs.sort()
	
	for i, diff in enumerate(diffs[:10]):
		pred_center = predict_center(frame, diff[1], diff[2])
		print(f"{i} center prediction: {pred_center}, diff sum = {diff}")


def predict_center(frame, best_upper_left, best_bottom_right):
	"""
	predicts the x,y center position of the disc based on the best box points from compute_box_scores
	assumes best_upper_left.x < best_bottom_right.x and best_upper_left.y < best_bottom_right.y
	"prediction" is just the center of the x,y points (mean)

	frame: frame that is NOT the release frame (all subsequent frames)
	best_upper_left: (x, y) of best box upper left
	best_bottom_right: (x, y) of best box bottom right

	returns predicted (x, y) center position in frame
	"""

	return (int((best_upper_left[0] + best_bottom_right[0]) / 2), int((best_upper_left[1] + best_bottom_right[1]) / 2))

