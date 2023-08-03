
<div align="center">
  <h1 style="color:blue;font-family:serif;font-style:oblique">CUB3D</h1>
</div>
#Introduction
***
This will be the first time you will be rendering something in  3D. For a lot of people this is hard to grasp, and that is completely fine. There are a number of documentations available to learn how to raycast. 
***


- ## RayCasting
    Raycasting is a rendering technique to create a 3D perspective in a 2D map. Back when computers were slower it wasn't possible to run real 3D engines in realtime, and raycasting was the first solution. Raycasting can go very fast, because only a calculation has to be done for every vertical line of the screen
	- [x] draw a simple map
	- [x] make player move
	- [x] put one ray
	- [x] make ray rotate
	- [x] determine the direction `<` `^` `>` and `v`
	***
	- [x] determine the coordinates `there is thre steps`
		- [x] `1` det coordinates that is represent a wall at the intersictions with __x__
		- [x] `2` det coordinates that is represent a wall at the intersictions with __y__
			- in the two steps above we should write a function that calculate the coord `(x,y)`
				and other one that check if you can  move to this coordinates
		- [x] `3` choos the coordinates that have a ray __R__ less than other
	- [x] make the ray stop if there are a wall in the next position
***




		cos(o) = x/R           &&             sin(o) = y/R


		tan(o) = sin(o)/cos(o)      =>        tan(o) = y/x


		x = y/tan(o)           &&             y = tan(o)*x
***



- ## Draw Walls
	- [x] darwing walls
	- [x] draw walls with texturs


***
### determine the coordonate of intersiction with y
![](image2.png)
### determine the coordonate of intersiction with x
![](image3.png)
***
![](https://permadi.com/tutorial/raycast/images/figure15.gif)
![](https://permadi.com/tutorial/raycast/images/figure16.gif)
***
##Before drawing the wall, there is one problem that must be taken care of. This problem is known as the “fishbowl effect.” Fishbowl effect happens because ray-casting implementation mixes polar coordinate and Cartesian coordinate together.

use this equation to get the coorect distance :
##correct distance  = ray_lenght  * cos(beta - delta); 
beta : player angle (rad)
delta : ray angle (rad)
***
#### link of github onwer [afadlane](https://github.com/Abdeladim-Fadlane)
