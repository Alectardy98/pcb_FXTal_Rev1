# FXTal A Drop In Replacement PCB For The IBM Model F XT

### Rev. 1 

This version has been tested and has been seen to function in both supported layouts.
The tested pcb was orderd from JLCPCB with a 0.8 thickness




Capacitive pad measurements have been largly taken dvjs project the mtf-capacitive, Other mesurements have been taken by NeonKight and myself from an origonal IBM F XT.

The PCB thickness should be 0.6mm or 0.08mm. This is thin enough to allow the board to flex into shape.

Standard glossy soldermask is probably the best choice. JLCPCB has had issues with wear on their black soldermask before. They have changed the formula, but a standard green/red/blue/yellow/purple/white/etc. glossy solder mask is probaby the safest bet for keyswitch wear resistance.
Higher wear resistance might also be achieved by coating the front of the capacitive pads in silkscreen, as silkscreen is an extra layer of epoxy. I am unsure how this will affect keyfeel or actuation, however.


For connecting the board to an xwhatsit or other controller, I would recommend 3M 8132/06 100, which has the correct pitch for this board and xwhatsit:
https://www.digikey.com/en/products/detail/3m/8132-06-100/7809902

The key matrix of the PCB is custom, made by myself guided by dvjs. The connector is likely in a slightly different position.

I did not clad the steel backplate in tape before mounting the PCB. The solder mask should provide adequate isolation. Just make sure the steel is clean and there are no burrs/jagged edges that could scrape the PCB.


| Authors |
| Alectardy98 |


| Special Thanks |

djvs - for generial and overall help

NeonKnight - for mesurments and reversenginering 

purdeaandrei - for writing the QMK firmware to work with xwhatsit
