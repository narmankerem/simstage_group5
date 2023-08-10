define laser ranger(

  sensor(
    range [ 0.0  5.6 ]
    fov 240.0
    samples 240
  )				

  color "green"
  size [ 0.06 0.06 0.06 ]

  block( points 4
     point[0] [0 0]
     point[1] [0 1]
     point[2] [1 1]
     point[3] [1 0]
     z [0 1]
  ) 
  
)

define simple_robot position(

block( 
    points 11
    point[0] [ 0.225 0.000 ]
    point[1] [ 0.208 0.086 ]
    point[2] [ 0.159 0.159 ]
    point[3] [ 0.086 0.208 ]
    point[4] [ 0.000 0.225 ]
    point[5] [ -0.086 0.208 ]
    point[6] [ -0.159 0.159 ]
    
    point[7] [ -0.000 -0.225 ]
    point[8] [ 0.086 -0.208 ]
    point[9] [ 0.159 -0.159 ]
    point[10] [ 0.208 -0.086 ]
    z [0 0.1]
  )

  odom_error [0.03 0.03 0.00 0.05]
  localization "odom"
  
  gui_nose 1
  drive "diff"
  color "pink"

  laser(pose [ 0.20 0.0 -0.2 0.0 ])
)

