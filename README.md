# PTERO-Remote
Unit for interfacing with the PTERODACTYL unit via xbee radio. Can either be used as an emergency data logger and as a siren toggle. 

Features include: 
  - Request currently active file name from PTERODACTYL (use to see if power was cycled and to easily get file name) 
  - Toggle Siren on/off 
  - Choose file name for download 
  - Choose unit radio ID for direct communication 
  - Download currently selected file from PTERODACTYL via xbee communication  
 
How to use: 
1) Plug in a 9-Volt battery to the unit
2) Within the code there is the option to have the right switch either toggle siren or toggle unit ID, choose one (default is siren toggle) 
3) Left Switch: Attempt to download currently selected file name 
4) Right Switch: Toggle Siren / Toggle ID 
5) Top Button: Increase file name by 10
6) Bottom Button: Increase file name by 1 
7) Both buttons AT THE SAME TIME: Request current file name 

Future addition ideas: Make ID an option always, add power switch to wiring 
