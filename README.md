##mjRotation

An external that can be used for the creation of elliptical, circular or linear motion paths. The inlet parameters are trajectory(0..1), ellipticalX(0..1) and ellipticalY(0..1). The outlet output (x,y) coordinates in the form of floats. It is possible to create pendular rectilinear motion over the Y axis and vice versa by sending ellipticalX = 0 and ellipticalY = 1 . The trajectory parameter can be driven by a phasor connected to a snapshot~ in PD to send floating point values from 0..1 to the trajectory inlet.
