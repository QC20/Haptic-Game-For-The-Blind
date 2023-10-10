# Haptic Game for the Blind

# HapNav
Welcome to the HapNav Game repository! This project aims to create an engaging and accessible game experience for the blind and visually impaired community. By harnessing the power of Arduino, this innovative game leverages multiple modalities to provide a unique gaming experience. It not only serves as an exciting game but also contributes to the field of accessibility research.

## HapNav Game Overview
HapNav challenges players to navigate a predefined map using a joystick module. The objective is to reach the end point of the map while staying on the predefined path. Here's a brief overview of the game:

### Game Objective
- The player uses a joystick module to navigate a map.
- If the player deviates from the predefined path, a vibrator activates with increasing intensity as the player moves further away from the path.
- To succeed, the player must steer back onto the main path, relying on trial-and-error to reach the finish line.

## The Big Picture
This project brings together technology, accessibility, and creativity to make gaming more inclusive. It's designed to be a valuable resource for designers, UX professionals, HCI researchers, and anyone interested in accessible technology. Here's what you'll find in this repository:

1. **Technical Specifications**: This project involves programming an .ino file in embedded C for Arduino. You'll find the code required to create a working game that meets the specified requirements.

2. **Level Map Design**: The game features a level map with distinct states, including starting points, turning points, and an end point. The level design consists of straight lines and 90-degree turns, providing a structured and engaging experience.

3. **Joystick Navigation**: The joystick module serves as the primary control mechanism. Players use it to guide their position on the level map. The code ensures that player movements align with the predefined path.

4. **Vibrator Feedback**: The game employs a vibrator component to provide feedback to the player. Vibrations vary in intensity based on the player's proximity to the predefined path, creating an immersive and tactile experience.

5. **Turn Point Indicators**: To aid player progress, the vibrator delivers quick, distinct vibrations when the player reaches a turning point. This feature enhances the player's sense of direction and progress.

6. **End Point Celebration**: Upon successfully completing the level, the game celebrates the player's achievement with a series of quick vibrations, indicating the level's completion.

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