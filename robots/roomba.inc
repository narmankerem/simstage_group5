define laser ranger(

  sensor(
    range [ 0.0  5.6 ]
    fov 240.0
    samples 240
  )				

  color "blue"
  size [ 0.06 0.06 0.06 ]

  block( points 4
     point[0] [0 0]
     point[1] [0 1]
     point[2] [1 1]
     point[3] [1 0]
     z [0 1]
  ) 
  
)



define roomba position
(
  size [0.33 0.33 0.1]

  # this block approximates the circular shape of a Roomba
  block( 
    points 16
    point[0] [ 0.225 0.000 ]
    point[1] [ 0.208 0.086 ]
    point[2] [ 0.159 0.159 ]
    point[3] [ 0.086 0.208 ]
    point[4] [ 0.000 0.225 ]
    point[5] [ -0.086 0.208 ]
    point[6] [ -0.159 0.159 ]
    point[7] [ -0.208 0.086 ]
    point[8] [ -0.225 0.000 ]
    point[9] [ -0.208 -0.086 ]
    point[10] [ -0.159 -0.159 ]
    point[11] [ -0.086 -0.208 ]
    point[12] [ -0.000 -0.225 ]
    point[13] [ 0.086 -0.208 ]
    point[14] [ 0.159 -0.159 ]
    point[15] [ 0.208 -0.086 ]
    z [0 0.1]
  )

  # this bumper array VERY crudely approximates the Roomba's bumpers
  bumper( size [.01 .01 .01 0]
          bcount 2  
          blength .33
          bpose[0] [0.12  0.12 .02  45]
          bpose[1] [0.12 -0.12 .02 -45] 
        )

  color "blue"
)

define create roomba( color "gray90" )
