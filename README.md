# irduino_stuff

This repo hold code to use [IRduino](https://www.crowdsupply.com/longan-lab/irduino) (which I highly recommend) to make my MASTERCOMMAND remote control playback/volume etc. on my computer.

Currently there are two modes (you must load separate code on for each, I don't have mode-switching yet):
1. Media Controller
  * Requires some keymappings on my mac to make volume up/down work as these are media keys and therefor not easy to access from irduino (lmk if I'm wrong)
  * uses volume keys, function +/- to zoom, 0 to pause... just look in the code for the rest :p
2. Social Media Controller
  * Works (nominally) on Facebook & Twitter
  * Facebook: Scroll stories, like, read more, open media (pic overlay), close media, cycle thru pics
  * Twitter: Scroll TL, like, open media (pic overlay), close media, cycle thru pics
  
## Known issues
* FB & Twitter both screw up if you use keyboard navigation a lot
* vol +/- requires custom mappings :frown: would like to fix this

## Todo
* [ ] make it so you can switch modes from media playback to social media browsing using a button
* [ ] switch urls from facebook to twitter to ??? so when one is boring you can "change channels" to the next

![JVC RM-C423 "MASTERCOMMAND" Remote Control](http://i.imgur.com/MIcJbns.jpg)
