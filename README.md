Introduction to interactive media final project documentation

Concept
Process (creative and workflow)
Execution 
Software
What worked
Issues and Errors 
Hardware
What worked
Issues and Errors
Graphics

Reflection/ Next steps


# Cooking Baba
## Concept
The concept for this project started with our own game experiences with physically interactive devices like the Wii-U and Nintendo Switch where the user would move the controllers around and the change would be reflected on the screen. We thought this was pretty similar and doable to what we could do with arduino and p5.js so we looked more into it. We recalled the steak cooking game in Mario party (image attached below) and decided to make a cooking game. We were also heavily inspired by cooking mama - a DS game that we played in our childhoods and decided to create a knockoff called cooking baba that would recreate a cooking experience by having all the tools and actions performed physically and little to no computer interaction (other than the visuals). 

<img width="662" alt="Screen Shot 2022-05-13 at 11 36 33 PM" src="https://user-images.githubusercontent.com/90758857/168379304-2109a5e8-9201-4202-a857-04c92d4fc09b.png">




## Process
To start off, we started planning what recipes we would want the user to cook. We decided to go with 3 recipes, a burger, a salad and a smoothie, to recreate an almost full-course meal! Then we started brainstorming what sensors will be used and what their applications will be. We wanted each recipe to be a unique experience that had some different mechanisms compared to the other recipes but we also wanted to have some functions like the grab and cutting functions that would be used in multiple recipes. We decided to use force sensors for the majority of the interactions, an accelerometer, a potentiometer and a button, their applications are as follows:
- Force sensors: we used a total of 5 force sensors:
- - To detect a grabbing motion, this was supposed to be attached to the glove 
- - To detect the cutting motion, this was supposed to be attached to the knife
- - To detect the presence of the cutting board, this was attached to one of the corners of the cutting board
- - 2 attached to the dressing bottles, to add dressings to the respective meals  
- Accelerometer was used to detect the flipping motion of the burger, it was supposed to be attached to the glove 
- Potentiometer was used to stimulate the motion of turning on/off a blender/ stove
- The button was used to progress through the different stages of cooking the recipe


After deciding on the recipes and sensor applications, we started by writing the code for the sensors and connecting them with p5.js on a basic level. After that we set up opencv and connected it with the required sensors, then we started coding the application of the sensors in the context of the game - the accelerometer to flip the burger, the knife to cut the vegetables, and open cv to move objects around. We applied these functions into each individual recipe and later on added these recipes into one final p5.js file.


## Execution: Software
We started coding the software by coding everything using the mouse and keyboard first to avoid having to set up the circuit everytime. We first coded functions used for more than one recipe individually and later on added them to their respective recipes. We had a different p5.js file for each recipe, we later combined these into one p5.js file. We decided to use classes for everything - the `cutting` class is for vegetables to be cut, the `cooking` class is to cook the burger, `fruits` is for the fruits in the smoothie recipe, `blender` and `blenderCap` are for the blender and lastly `toppings` is for the toppings that can be added to the salad. These classes became an essential part of the code as we used them for every item, this made it so much easier to write the code and our appreciation for classes grew greater (thank god for classes). We also realised that we should have used better naming conventions for our classes and variables as combining all the recipes became troublesome because of same variable names and some of the class names were a bit ambiguous (like “Cooking” class for the burger 🤦) which made the code a little hard to follow. 


### Code for the classes

**Cooking Class** 
``` javaScript
class Cook {
  constructor(x, y, img) {
    this.x = x;
    this.y = y;
    this.cookLevel = img;
    this.index = 0;
    this.burnt = burntPatty;
    this.lastStage = false;
    this.pattyFlipped = false;
    this.isBurnt = false;
    this.topBurnt = false;
    this.onStove = true;
    this.cooking = false;
    this.doneCooking = false;
  }

  burn() {
    if (
      this.index >= noRaw - 1 &&
      !this.isBurnt &&
      frameCount % 400 == 0 &&
      !this.pattyFlipped
    ) {
      this.isBurnt = true;
      this.cookLevel = burntImgs;
      this.topBurnt = true;
      this.burnt = burntPatty;
    }

    if (this.index >= this.cookLevel.length - 1 && frameCount % 400 == 0) {
      this.isBurnt = true;
      this.burnt = utterlyBurnt;
    }
  }
  cook() {
    image(steamImg, 333, 166, steamImg.width / 2, steamImg.height / 2);
    this.burn();
    if (this.index < noRaw - 1 && frameCount % 60 == 0 && !this.isBurnt) {
      this.index++;
    } else if (
      !this.topBurnt &&
      this.pattyFlipped &&
      this.index < noTop + noRaw + noFlip - 1 &&
      frameCount % 60 == 0
    ) {
      if (mouseIsPressed) {
        rect(width / 2, height / 2, 200, 200);
      }
      this.index++;
    } else if (
      this.topBurnt &&
      this.pattyFlipped &&
      this.index < this.cookLevel.length - 1 &&
      frameCount % 60 == 0
    ) {
      if (mouseIsPressed) {
        rect(width / 2, height / 2, 200, 200);
      }
      this.index++;
    }
  }

  flip() {
    if (this.index >= noRaw - 1 && !this.pattyFlipped) {
      if (this.topBurnt) {
        this.index = 0;
      } else {
        this.index++;
        this.pattyFlipped = true;
      }

      if (!this.topBurnt && this.index >= noRaw + noFlip - 2) {
        // this.pattyFlipped = true;
        this.isBurnt = false;
      } else if (this.topBurnt && this.index <= 1) {
        this.pattyFlipped = true;
        this.isBurnt = false;
      }
      // print("flip");
    }
  }

  accelerate() {
    // print(xVanl);
    if (xVal <= -0.3) {
      borgir.flip();
    }
  }

  grab() {
    if (
      xtemp >= this.x - 110 &&
      xtemp <= this.x + 110 &&
      yPos >= this.y - 60 &&
      yPos <= this.y + 60 &&
      forceGrab > 100
    ) {
      this.x = xtemp;
      this.y = yPos;
      print("grab");
    }
  }

  display() {
    if (stove >= 500 && this.onStove) {
      this.cook();
      this.accelerate();
      this.cooking = true;
      this.doneCooking = false;
    }

    if (stove <= 500 && this.cooking) {
      this.doneCooking = true;
      this.cooking = false;
    }

    if (this.doneCooking && burgerStage == 2) {
      this.grab();
    }

    // this.cook();

    if (!this.isBurnt) {
      image(this.cookLevel[this.index], this.x, this.y, 110, 60);
    } else {
      image(this.burnt, this.x, this.y, 110, 60);
    }
  }
}
```
**Cutting Class**

``` javaScript
class Cutting {
  constructor(x, y, w, h, img, veggie) {
    //initital values of x nd y to set them to out them back on th shelf
    this.initX = x;
    this.initY = y;
    this.x = x;
    this.y = y;
    this.img = img;
    this.w = w;
    this.h = h;
    this.index = 0;
    this.slices = [];
    this.vegSlice = veggie;
    this.grabbed = false;
    this.onBoard = false;
    this.cut = false;
    this.canSlice = false;
    this.randX = random(715 + 25, 850 - 20);
    this.randY = random(350 + 20, 400 - 20);
    this.randX2 = random(715 + 25, 850 - 20);
    this.randY2 = random(350 + 20, 400 - 20);
    this.inBowl = false;
    this.cutComplete = false;
  }

  move() {
    // if (this.grabbed && !this.onBoard) {
    if (this.grabbed) {
      this.x = xtemp;
      this.y = yPos;
    }
  }

  slicing() {
    if (
      forceKnife > 100 &&
      this.cut &&
      this.index < this.img.length &&
      this.onBoard
    ) {
      this.index++;
      this.slices.push(this.vegSlice);
    } else {
      this.index += 0;
      this.cutComplete = true;
    }
    // this.cut = false;
  }

  drop() {
    if (
      this.x - this.w >= 577 &&
      this.x + this.w <= 830 &&
      this.y + this.h >= 170 &&
      this.y - this.h <= 260 &&
      !this.grabbed
    ) {
      this.onBoard = true;
      this.x = 618;
      this.y = 218;
      this.cut = true;
    }
  }
  display() {
    this.move();

    this.drop();
    // this.fall();
    if (this.index < this.img.length) {
      image(
        this.img[this.index],
        this.x,
        this.y,
        this.w,
        this.h
        // this.img[this.index].width / 20,
        // this.img[this.index].height / 20
      );
    }
    if (forceBoard >= 5 && !this.inBowl) {
      for (let i = 0; i < this.slices.length; i++) {
        image(
          this.slices[i],
          686 + i * 30,
          197,
          this.slices[i].width / 3,
          this.slices[i].height / 3
        );

        image(
          this.slices[i],
          686 + i * 30,
          240,
          this.slices[i].width / 3,
          this.slices[i].height / 3
        );
      }
    } else if (this.cutComplete) {
      this.inBowl = true;
      for (let i = 0; i < this.slices.length; i++) {
        image(
          this.slices[this.slices.length - 1],
          this.initX,
          this.initY,
          this.slices[this.slices.length - 1].width / 3,
          this.slices[this.slices.length - 1].height / 3
        );

        image(
          this.slices[this.slices.length - 1],
          this.initX + 30,
          this.initY,
          this.slices[this.slices.length - 1].width / 3,
          this.slices[this.slices.length - 1].height / 3
        );
      }
    }
  }

  display2() {
    for (let i = 0; i < this.slices.length; i++) {
      image(
        this.slices[this.slices.length - 1],
        this.randX - 340,
        this.randY,
        this.slices[this.slices.length - 1].width / 3,
        this.slices[this.slices.length - 1].height / 3
      );

      image(
        this.slices[this.slices.length - 1],
        this.randX2 - 340,
        this.randY2,
        this.slices[this.slices.length - 1].width / 3,
        this.slices[this.slices.length - 1].height / 3
      );
    }
  }
  display3() {
    this.move();
    image(
      this.vegSlice,
      this.x,
      this.y,
      this.vegSlice.width / 2,
      this.vegSlice.height / 2
    );
  }
}
```
**Fruits Class**

```javaScript
class Fruit {
  constructor(x, y, w, h, img) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.img = img;
    this.inBlender = false;
    this.grabbed = false;
    this.fallen = false;
    // this.rest
  }

  move() {
    if (this.grabbed && !this.fallen) {
      this.x = xtemp;
      this.y = yPos;
      // this.grabbed = true;
      // globalGrabbed = true;
      // print("works");
    }
  }

  fall() {
    if (
      !this.grabbed &&
      this.x - this.w / 2 - 10 >= blenderClass.x - blenderClass.w / 2 &&
      this.x + this.w / 2 <= blenderClass.x + blenderClass.w / 2 - 10 &&
      this.y + this.h / 2 <= blenderClass.y
    ) {
      this.y++;
      this.fallen = true;

      if (this.w > 60) {
        this.w = this.w / 2;
        this.h = this.h / 2;
      }
    }
  }
  //   release(){

  //   }

  display() {
    this.move();
    this.fall();
    image(this.img, this.x, this.y, this.w, this.h);
  }
}
```
**Toppings Class** 
```javaScript
class Topping {
  constructor(x, y, div, div2, img) {
    this.x = x;
    this.y = y;
    this.img = img;
    this.w = this.img[0].width/div;
    this.h = this.img[0].height/div;
    this.randX = random(398+20, 514 - 20);
    this.randX2 = random(398+20, 514 -20);
    // this.squeezed
    this.squeezed = false;
    this.inBowl = false;
    this.grabbed = false;
    this.div2 = div2;
  }

  squeeze() {
    if (this.squeezed || this.inBowl) {
      image(
        this.img[1],
        this.randX,
        315,
        this.img[1].width/this.div2,
        this.img[1].height/this.div2
      );
      image(
        this.img[1],
        this.randX2,
        315,
        this.img[1].width/this.div2,
        this.img[1].height/this.div2
      );
    }
  }

  move() {
    // if (this.grabbed && !this.onBoard) {
    if (this.grabbed && !this.inBowl) {
      this.x = xtemp;
      this.y = yPos;
    }
  }

  drop() {
    if (
      this.x - this.w >= 240 &&
      this.x + this.w <= 575 &&
      this.y + this.h >= 425 &&
      this.y - this.h <= 356 &&
      !this.grabbed
    ) {
      this.inBowl = true;
      this.x = this.randX;
      this.y = 315;
      // this.cut = true;
    }
  }

  display() {
    // this.squeeze();
    // this.move();
    // this.drop();
  if(!this.squeezed && !this.inBowl){
    image(this.img[0], this.x, this.y, this.w, this.h);
  } else{
    this.squeeze();
  }
  }
  
  display2(){
    if(this.squeezed || this.inBowl){
      this.display();
    }
  }
}
```

**Blender Class**
``` javaScript
class Blender {
  constructor() {
    this.x = width / 2;
    this.y = height / 2;
    this.w = blender.width / 2.5;
    this.h = blender.height / 2.5;
    // this.cap = blenderCap
    this.blendImgs = blenderShake;
    this.speed = 0;
    this.blendIndex = 1;
    this.blending = false;
    this.doneBlending = false;
  }

  blend() {
    if (pot <= 160) {
      this.speed = 0;
    } else if (pot > 160 && pot <= 700) {
      this.speed = 5;
    } else {
      this.speed = 5;
    }

    //     if (blenderHat.onBlender && this.speed>0 && frameCount %this.speed == 0){
    //       for (let i = 1; i < this.blendImgs.length; i++){
    //         image(this.blendImgs[i],  501, 243, this.blendImgs[i].width, this.blendImgs[i].height);
    //       }

    //     }

    if (blenderHat.onBlender && this.speed > 0) {
      // for(let i = 1; i < 3; i++){
      this.blending = true;
      this.doneBlending = false;
      if (frameCount % 11 == 0 && this.blendIndex == 1) {
        this.blendIndex = 2;

        // }
      } else if (frameCount % 23 == 0) {
        this.blendIndex = 1;
      }
      image(
        this.blendImgs[this.blendIndex],
        501,
        290,
        this.blendImgs[this.blendIndex].width / 2.5,
        this.blendImgs[this.blendIndex].height / 2.5
      );
    } else if (blenderHat.onBlender && this.speed == 0) {
      // this.blending = false;
      if (this.blending) {
        this.blending = false;
        this.doneBlending = true;
      } else if(!this.doneBlending){
        image(
          this.blendImgs[0],
          501,
          290,
          this.blendImgs[0].width / 2.5,
          this.blendImgs[0].height / 2.5
        );
      }
    }
  }

  display() {
    this.blend();
    if (this.doneBlending) {
      textSize(20);
      text("you made a delicious smoothie!", 350, 100);
      image(smoothieEnd, 500, 350, smoothieEnd.width/3, smoothieEnd.height/3);
    } else {
      image(blender, this.x, this.y, blender.width / 2.5, blender.height / 2.5);
    }
  }
}
```


### What worked:
While most of the game works smoothly, these are the recipe specific things that we are especially proud of.	

- Burger: The burger must’ve been the hardest thing to code, especially since we wanted most of it to be user-dependent, meaning that the vegetables that were added in the assembling stage are only those that the user cut in the first stage. We also made it so that the user can cook the burger on different levels on both sides, so they could have one side that is completely burnt and the other is still raw or maybe both of them were at the perfect cooked level. We feel that these functions worked out pretty well (despite some obstacles that faced us while trying to get them to work), and that they greatly improved the overall user experience. 
- Salad: Just like the burger, the salad was also dependent on the choices made by the user. The vegetables added to the bowl were those cut by the user and those same vegetables were used for different stages of the recipe. We feel like this made the game unique and interesting to play more than once as the user will be able to make something different each time. Cutting the vegetables also allowed us to add another dimension to the game, which was the physical to arduino to p5.js interaction (knife/ cutting board ->force sensors -> arduino -> p5.js)
- Smoothie: Overall we were pretty happy with how the blender stages progress, especially the blending function where the user has to close the blender using the cap before blending it and how it would display the smoothie after they switch off the blender.


We however had issues with setting up opencv to the correct canvas size because of the mirrored nature of opencv but with help from the professor we were able to make it work (thank you professor <3). We also had trouble with the grab function where it would grab multiple objects at once but once again we were able to resolve this issue with guidance from the professor (thank you again 🥰). Overall, we had a lot of issues with the coding, most of them which were caused because of sleep deprivation, but thankfully we were able to solve most of them. 

### What didn't work: 
We faced a lot of issues while coding, most of them were tied to the use of time delays and user-dependent conditions. 


The time delay issues were especially concerned with the cooking of the burger, we needed to have a way to measure the time taken since the burger started cooking and a way to change the image used based on that. We eventually got `frameCount` to work for this specific application but in another case - blending the smoothie - we initially wanted the speed of blending to depend on the value of the potentiometer but due to the absence of a delay function we were unable to do that and instead decided to have a uniform speed for the blending.
 

Another issue that we did not have sufficient time to resolve is a small issue with the cutting function where the sprites would not appear correctly, they would appear too fast or too slow. We assumed this is because of the values from the force sensors and these functions worked well when we tried them out with a keyboard.


The progression of the game using the button did not work either - it worked well when it was the only sensor connected however when it was connected with other sensors, the value (1) which was used to progress through the game was printed more than once, which led to the restarting the game rather than progressing through one step at a time. We were told that adding a debounce would work, but later on discovered that although this decreased the amount of times the value 1 was printed, it was still not enough and we haven't been able to figure out a solution to this problem yet :(

There was also a problem with the assembling of the burger, where the ingredients would stick to the ellipse rather than drop in their correct places, this was especially unusual as the same grab function that is used throughout the code was used here and yet this was the only place where it didn't work. Other than these issues, there were no other issues experienced with the code, and we believe that if we had a little more time we might have been able to debug these errors and perfect the code. 


### User Testing:
We had our friends try out the game and tell us their thoughts, one of the improvements that was suggested was to add something that indicated that the burger was being cooked so we added the steam image that would appear when the burger started cooking. 

we also added an instructions page as we found that the users struggled to understand the controls for the game 

![WhatsApp Image 2022-05-13 at 11 32 31 PM (1)](https://user-images.githubusercontent.com/90758857/168379435-10bea74d-9fb3-41cf-b7ca-6849ee7a14d0.jpeg)
![burgerInstructions](https://user-images.githubusercontent.com/90758857/168379649-afeb7b41-1649-484e-a459-4e6b9ff70e27.png)
![saladInstructions](https://user-images.githubusercontent.com/90758857/168379655-b0e47639-e525-4418-bcac-e761b729f21b.png)

![smoothieInstructions](https://user-images.githubusercontent.com/90758857/168379664-14dd42e6-9b6b-4b05-a8cc-ff8724df9627.png)

## Execution: Hardware

Soldering was another aspect of our process that turned out to be quite time consuming and a bit difficult. The number of sensors and wires needed to make each individual sensor work also added to the difficulty of soldering (each force sensor alone needed 6 connections alones, so 5x6=30 wires needed to be soldered just for the force sensors).
We started the soldering process by deciding where each sensor was going to be placed (for ease and mobility when playing). We also realized that the accelerometer needed to be put in the arduino directly since it was the only sensor connected to 3.3V.
It was also at this tage that we realised we needed more analog pins than our Arduino Uno could fit, so we used an Arduino Mega.
All the sensors needed to have 1) a header soldered on to avoid damage to the sensor, 2) a pin on the analog wire to be placed directly on to the Arduino.
Since we had around 18 wires dangling all over the place, we decided to twist some of them together with the help of a drill (thank you professor for the brilliant idea).
Some other difficulties faced - and one of the reasons we could not finish the project in time, nor use the soldered circuit board- was that we had a short circuit that prevented the arduino from turning on, as well as a few misconnections, broken off wires… .
Overall, we would say that soldering everything on was very laborious and time consuming, but nonetheless taught us a skill that will be beneficial in future projects and allowed for more mobility in our setup.


## Graphics
We created most of the graphics for the game ourselves as we could not find what we were looking for online. The graphics were created using ProCreate and Adobe Illustrator. We added an instruction page at the beginning of each recipe to help the user understand how to navigate through the game. We also wanted to stay true to the kitchen theme so we designed recipe specific locations within the kitchen as the backgrounds for the respective recipes. 

![intro](https://user-images.githubusercontent.com/90758857/168379478-20d15ded-8cb3-470c-a507-1cbf6bd23f38.png)
![choice](https://user-images.githubusercontent.com/90758857/168379490-c875e2a6-7f46-4c59-ab55-5cd1e88d8455.png)
![burgerBg-01](https://user-images.githubusercontent.com/90758857/168379687-bbb6961c-a3ac-4d43-9aef-dbcc00bb06ec.png)
![saladBg](https://user-images.githubusercontent.com/90758857/168379719-3ceb742d-9540-4af0-aaea-3e3865b387f2.png)
![smoozieBG](https://user-images.githubusercontent.com/90758857/168379748-5489c3f4-095b-46c7-b9b7-5aefe1013fcc.png)



## Reflection
We learnt a lot through this project – but mainly we learnt that we should better assess the time we have and match it with our abilities before we set our ambitions too high. We realised that with all the deadlines, perfecting this project into what we were expecting it to be was impossible within the given timeframe. Although we came pretty close to what we wanted to make, this project did not turn out how we envisioned it to, which was disappointing. We hope to work on this project again in the summer to make it into the game we initially wanted to create.


## Links & Gallery

[Full game link](https://editor.p5js.org/daniaezz/sketches/isK_SNqxD)

[Burger link](https://editor.p5js.org/daniaezz/sketches/tw3O2XcPq)

[Salad link](https://editor.p5js.org/daniaezz/sketches/hNygZxeMY)

[Smoothie link](https://editor.p5js.org/daniaezz/sketches/_-Al1b7FB)

[Burger video link](https://youtu.be/jqpK6dxj2ls)

   Disclaimer: For the filming of this video (the burger video), unfortunately I was unable to find a substitute for something to act as the cutting board, which caused some errors while printing the cutting sprites. The flipping motion was also delayed due to the decrease in framerate to try and make the button work.

[Salad video link](https://youtu.be/9L0OaKVCOEY) 

[Smoothie video link](https://youtu.be/cO8r13EGdsI) 
