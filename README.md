# Cooking Baba
## Concept

The concept for this project started with our own game experiences with physically interactive devices like the Wii-U and Nintendo Switch where the user would move the controllers around and the change would be reflected on the screen. We thought this was pretty similar and doable to what we could do with arduino and p5.js so we looked more into it. We recalled the steak cooking game in Mario party (image attached below) and decided to make a cooking game. We were also heavily inspired by cooking mama - a ds game that we played in our childhoods and decided to create a knockoff called cooking baba that would recreate a cooking experience by having all the tools and actions performed physically and little to no computer interaction (other than the visuals). 

## Process

To start off, we started planning what recipes we would want the user to cook. We decided to go with 3 recipes, a burger, a salad and a smoothie, to recreate an almost full-course meal. Then we started brainstorming what sensors will be used and what their applications will be. We wanted each recipe to be a unique experience that had some different mechanisms compared to the other recipes but we also wanted to have some functions like the grab and cutting functions that would be used in multiple recipes. We decided to use force sensors for the majority of the interactions, an accelerometer, a potentiometer and a button, their applications are as follows:
Force sensors: we used a total of 5 force sensors:
To detect a grabbing motion, this was supposed to be attached to the glove 
To detect the cutting motion, this was supposed to be attached to the knife
To detect the presence of the cutting board, this was attached to one of the corners of the cutting board
2 attached to the dressing bottles, to add dressings to the respective meals  
Accelerometer was used to detect the flipping motion of the burger, it was supposed to be attached to the glove 
Potentiometer was used to stimulate the motion of turning on/off a blender/ stove
The button was used to progress through the different stages of cooking the recipe

After deciding on the recipes and sensor applications, we started by writing the code for the sensors and connecting them with p5.js on a basic level. After that we set up opencv and connected it with the required sensors, then we started coding the application of the sensors in the context of the game - the accelerometer to flip the burger, the knife to cut the vegetables, and open cv to move objects around. We applied these functions into each individual recipe and later on added these recipes into one final p5.js file.


## Execution: Software

We started coding the software by coding everything using the mouse and keyboard first to avoid having to set up the circuit everytime. We first coded functions used for more than one recipe individually and later on added them to their respective recipes. We had a different p5.js file for each recipe, we later combined these into one p5.js file. We decided to use classes for everything - the cutting class is for vegetables to be cut, the cooking class is to cook the burger, fruits is for the fruits in the smoothie recipe, blender and blenderCap are for the blender and finally toppings is for the toppings that can be added to the salad. These classes became an essential part of the code as we used them for every item, this made it so much easier to write the code and our appreciation for classes grew greater (thank god for classes). We also realised that we should have used better naming conventions for our classes and variables as combining all the recipes became troublesome because of same variable names and some of the class names were a bit ambiguous (like Cooking class for the burger 🤦) which made the code a little hard to follow. 

### What worked:

While most of the game works smoothly, these are the recipe specific things that we are especially proud of.	
Burger: The burger must’ve been the hardest thing to code, especially since we wanted most of it to be user-dependent, meaning that the vegetables that were added in the assembling stage are only those that the user cut in the first stage. We also made it so that the user can cook the burger on different levels on both sides, so they could have one side that is completely burnt and the other is still raw or maybe both of them were at the perfect cooked level. We feel that these functions worked out pretty well and that they would greatly improve the overall user experience. 
Salad: just like the burger, the salad was also dependent on the choices made by the user. The vegetables added to the bowl were those cut by the user and those same vegetables were used for different stages of the recipe. We feel like this made the game unique and interesting to play more than once as the user will be able to make something different each time.
Smoothie: overall we were pretty happy of how the blender stages progress, especially the blending function where the user has to close the blender using the cap before blending it and how it would display the smoothie after they switch off the blender
We had issues with setting up opencv to the correct canvas size because of the mirrored nature of opencv but with help from the professor we were able to make it work (thank you professor <3). We also had trouble with the grab function where it would grab multiple objects at once but once again we were able to resolve this issue with guidance from the professor (thank you again 🥰). Overall, we had a lot of issues with the coding, most of them which were caused because of sleep deprivation, but thankfully we were able to solve most of them. 

### What didn't work: 

We faced a lot of issues while coding, most of them were tied to the use of time delays and user-dependent conditions. The time delay issues were especially concerned with the cooking of the burger, we need to have a way to measure the time taken since the burger started cooking and a way to change the image used based on that. We eventually got frameCount to work for this specific application but in another case - blending the smoothie - we initially wanted the speed of blending to depend on the value of the potentiometer but due to the absence of a delay function we were unable to do that and instead decided to have a uniform speed for the blending. Another issue that we did not have sufficient time to resolve is a small issue with the cutting function where the sprites would not appear correctly, they would appear too fast or too slow. We assumed this is because of the values from the force sensors and these functions worked well when we tried them out with a keyboard. The progression of the game using the button did not work either - it worked well when it was the only sensor connected however when it was connected with other sensors, the value (1) which was used to progress through the game was printed more than once, which led to the restarting the game rather than progressing through one step at a time. We were told that adding a debounce would work, but later on discovered that although this decreased the amount of times the value 1 was printed, it was still not enough and we haven't been able to figure out a solution to this problem yet :(. There was also a problem with the assembling of the burger, where the ingredients would stick to the ellipse rather than drop in their correct places, this was especially unusual as the same grab function that is used throughout the code was used here and yet this was the only place where it didn't work. Other than these issues, there were no other issues experienced with the code, and we believe that if we had a little more time we might have been able to debug these errors and perfect the code. 


## Execution: Hardware

Essential tools that were used: 
Glove with a unique colour to be detected using opencv
Idk 

## Graphics
We created most of the graphics for the game ourselves as we could not find what we were looking for online. We added an instruction page at the beginning of each recipe to help the user understand how to navigate the game. We also wanted to stay true to the kitchen theme so we designed recipe specific locations within the kitchen as the backgrounds for the respective recipes. 

![intro](https://user-images.githubusercontent.com/90758857/168352319-f56ec922-5a3d-4acc-a4d9-a2c992db9366.png)

![choice](https://user-images.githubusercontent.com/90758857/168352482-9968f115-86d5-476c-82ac-db43957edd2e.png)

![burgerInstructions](https://user-images.githubusercontent.com/90758857/168352577-9c207317-a582-4930-8745-aa4c90a9ee79.png)
![saladInstructions](https://user-images.githubusercontent.com/90758857/168352701-834a643e-5d75-427d-bcf7-c4a5b6524389.png)
![smoothieInstructions](https://user-images.githubusercontent.com/90758857/168352783-bbf983d2-4d69-4b0f-b7f8-b0f7053968e6.png)
![burgerBg-01](https://user-images.githubusercontent.com/90758857/168353842-81d1062c-65a7-4b4c-bba8-2df7f967fb8b.png)

![saladBg](https://user-images.githubusercontent.com/90758857/168353957-104b81e3-e740-4c70-89a2-31810c7eb32a.png)
![smoozieBG](https://user-images.githubusercontent.com/90758857/168354027-b24c75c2-c956-4ce4-9522-499acf589f44.png)

## Reflection
We learnt a lot through this project – but mainly we learnt that we should better assess the time we have and match it with our abilities before we set our ambitions too high. We realised that with all the deadlines, perfecting this project into what we were expecting it to be was impossible within the given timeframe. Although we came pretty close to what we wanted to make, this project did not turn out how we envisioned it to, which was disappointing. We hope to work on this project again in the summer to make it into the game we initially wanted to create.


## Links & Gallery

[Full game link](https://editor.p5js.org/daniaezz/sketches/isK_SNqxD)

[Burger link](https://editor.p5js.org/daniaezz/sketches/tw3O2XcPq)

[Salad link](https://editor.p5js.org/daniaezz/sketches/hNygZxeMY)

[Smoothie link](https://editor.p5js.org/daniaezz/sketches/_-Al1b7FB)

[Burger video link](https://youtu.be/jqpK6dxj2ls)

Disclaimer: For the filming of this video (the burger video), unfortunately I was unable to find a substitute for something to act as the cutting board, which caused some errors while printing the cutting sprites. The flipping motion was also delayed due to the decrease in framerate to try and make the button work.

 
