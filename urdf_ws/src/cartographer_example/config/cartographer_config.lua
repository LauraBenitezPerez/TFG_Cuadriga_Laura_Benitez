include "cartographer/configuration_files/demo_backpack_2d.lua"

MAP_FRAME = "map"
POSE_GRAPH_FRAME = "odom"
TRAJECTORY_FRAME = "base_link"

TRAJECTORY_BUILDER_2D.num_accumulated_range_data = 1
POSE_GRAPH.optimize_every_n_nodes = 90

TRAJECTORY_BUILDER_2D.max_range = 35.0
TRAJECTORY_BUILDER_2D.min_range = 0.2
TRAJECTORY_BUILDER_2D.voxel_filter_size = 0.05