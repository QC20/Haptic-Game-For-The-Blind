# Haptic Game for the Blind

![alt text](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Prototypes-images/ESP32-Prototype/KRG7e.jpeg)
![alt-text-1](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Prototypes-images/ESP32-Prototype/KRG7e.jpeg) ![alt-text-2](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Project-Article-Contents/Inspiration/haptic_joystick_hand.jpeg)
# HapNav
Welcome to the HapNav Game repository! This project aims to create an engaging and accessible game experience for the blind and visually impaired community. By harnessing the power of Arduino, this innovative game leverages multiple modalities to provide a unique gaming experience. It not only serves as an exciting game but also contributes to the field of accessibility research.

## HapNav Game Overview
HapNav challenges players to navigate a predefined map using a joystick module. The objective is to reach the end point of the map while staying on the predefined path. Here's a brief overview of the game:

![alt text](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Prototypes-images/ESP32-Prototype/fYYAm.jpeg)

### Game Objective
- The player uses a joystick module to navigate a map.
- If the player deviates from the predefined path, a vibrator activates with increasing intensity as the player moves further away from the path.
- To succeed, the player must steer back onto the main path, relying on trial-and-error to reach the finish line.

![alt text](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Diagrams/ESP32-Demo_Haptic-Diagram/wiring_diagram.png)

## The Big Picture
This project brings together technology, accessibility, and creativity to make gaming more inclusive. It's designed to be a valuable resource for designers, UX professionals, HCI researchers, and anyone interested in accessible technology. Here's what you'll find in this repository:

1. **Technical Specifications**: This project involves programming an .ino file in embedded C for Arduino. You'll find the code required to create a working game that meets the specified requirements.

```
// Representation of a game map-level design.
// 0 represents the level path. 1-5 is increasing vibration intensity as you get further away from the desired path

const int numRows = 25;  // Number of rows in the map
const int numCols = 25;  // Number of columns in the map

// Define the map using a 2D array
int map[numRows][numCols] = {

[[5. 5. 4. 3. 2. 1. 0. 1. 2. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 1. 0. 1. 2. 3. 4. 4. 4. 4. 4. 4. 4. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 1. 0. 1. 2. 3. 3. 3. 3. 3. 3. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 1. 0. 1. 2. 2. 2. 2. 2. 2. 2. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 1. 0. 1. 1. 1. 1. 1. 1. 1. 2. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 1. 0. 0. 0. 0. 0. 0. 0. 1. 2. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 1. 1. 1. 1. 1. 1. 1. 0. 1. 2. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5.]
 [5. 5. 4. 3. 2. 2. 2. 2. 2. 2. 2. 1. 0. 1. 2. 3. 4. 4. 4. 4. 4. 4. 4. 5. 5.]
 [5. 5. 4. 3. 3. 3. 3. 3. 3. 3. 2. 1. 0. 1. 2. 3. 3. 3. 3. 3. 3. 3. 5. 5. 5.]
 [5. 5. 4. 4. 4. 4. 4. 4. 4. 3. 2. 1. 0. 1. 2. 2. 2. 2. 2. 2. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 1. 1. 1. 1. 1. 1. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 0. 0. 0. 0. 0. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 1. 1. 1. 1. 1. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 2. 2. 2. 2. 2. 2. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 5. 4. 3. 3. 3. 3. 3. 3. 3. 2. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 4. 4. 4. 4. 4. 4. 4. 3. 2. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 3. 3. 3. 3. 3. 3. 3. 2. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 2. 2. 2. 2. 2. 2. 2. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 1. 1. 1. 1. 1. 1. 1. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 0. 0. 0. 0. 0. 0. 0. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 1. 1. 1. 1. 1. 1. 1. 1. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 1. 2. 2. 2. 2. 2. 2. 2. 2. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 1. 2. 3. 3. 3. 3. 3. 3. 3. 3. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 1. 2. 3. 4. 4. 4. 4. 4. 4. 4. 4. 5. 5.]
 [5. 5. 5. 5. 5. 5. 5. 4. 3. 2. 1. 0. 1. 2. 3. 4. 5. 5. 5. 5. 5. 5. 5. 5. 5.]]
}
```

3. **Level Map Design**: The game features a level map with distinct states, including starting points, turning points, and an end point. The level design consists of straight lines and 90-degree turns, providing a structured and engaging experience.

![alt text](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Game-Level-Designs/Level-2-Visualization.png)

4. **Joystick Navigation**: The joystick module serves as the primary control mechanism. Players use it to guide their position on the level map. The code ensures that player movements align with the predefined path.

![Click to see the STL files of the Controller](https://github.com/QC20/Haptic-Game-For-The-Blind/blob/master/Controller-Designs/Thick-Remote-Design/Original-Design-Combined.stl)

5. **Vibrator Feedback**: The game employs a vibrator component to provide feedback to the player. Vibrations vary in intensity based on the player's proximity to the predefined path, creating an immersive and tactile experience.

6. **Turn Point Indicators**: To aid player progress, the vibrator delivers quick, distinct vibrations when the player reaches a turning point. This feature enhances the player's sense of direction and progress.

7. **End Point Celebration**: Upon successfully completing the level, the game celebrates the player's achievement with a series of quick vibrations, indicating the level's completion.

## Get Started

If you're ready to dive into this exciting project, follow these steps:

1. Clone the repository to your local machine.
2. Review the code in the .ino file to understand the game logic and mechanics.
3. Set up your Arduino environment and upload the code to your Arduino board.
4. Connect the required hardware components, including the joystick module and vibrator, following the provided instructions.
5. Playtest the game to experience firsthand how it combines accessibility and fun.

## Contribution
We welcome contributions from the open-source community to enhance the game's accessibility features, user experience, and overall quality. If you have ideas, suggestions, or improvements to share, please feel free to open issues or submit pull requests.

Let's work together to make gaming more inclusive and enjoyable for everyone!

## Acknowledgments
We would like to express our gratitude to the blind and visually impaired community for their valuable insights and feedback during the development of this project. Your input has been instrumental in creating a meaningful and accessible gaming experience.

---

By contributing to this project, you are not only advancing the world of accessible gaming but also participating in cutting-edge accessibility research. We hope you find this project inspiring and valuable to the designer, UX, HCI, and research communities.
