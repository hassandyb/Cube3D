

# cub3D: Experience the Magic of 3D Mazes

Welcome to **cub3D**! Imagine stepping into a 3D maze where you control the view and explore as if you were really there. Inspired by the groundbreaking game Wolfenstein 3D, **cub3D** is a fun project that lets you experience the thrill of navigating through a maze in a first-person perspective.

## 🕹️ What is cub3D?

**cub3D** is a project where you get to create a 3D maze view on your computer screen. It’s like building your own mini version of an old-school 3D game. You’ll use special techniques called ray-casting to make the maze come alive and let you explore it just like in classic games.

## ✨ Features

- **3D Maze View**: See and move around a maze in three dimensions.
- **Textured Walls**: Walls in the maze will have different textures, making it look realistic and exciting.
- **Colorful Floors and Ceilings**: Choose colors for the floor and ceiling to match the mood of your maze.
- **Simple Controls**:
  - **Arrow Keys**: Look around in different directions.
  - **W, A, S, D**: Move forward, backward, left, and right.
  - **ESC Key**: Exit the maze or close the window.

## 🛠️ How It Works

Here’s a simplified breakdown of how everything fits together:

1. **The Maze**: Imagine the maze as a grid. Each part of the grid is represented by simple characters in a file. Some characters show walls, others show where you start, and some are just open spaces.
2. **Textures**: These are like images you apply to the walls to make them look interesting. Different images are used based on which way the wall is facing.
3. **Colors**: You can set the colors of the floor and ceiling to make the maze feel just right.
4. **Your View**: As you move around, the game updates your view to show what you’d see if you were actually in the maze.

## 🎨 Example

Here’s a little example to give you an idea:

- **Textures**: Imagine you have images for walls (e.g., bricks, stone).
- **Colors**: Choose colors for the floor (like a nice brown) and the ceiling (maybe a light blue).
- **Maze Layout**: The maze file might look something like this:


NO ./textures/brick_wall.xpm
SO ./textures/stone_wall.xpm
WE ./textures/wood_wall.xpm
EA ./textures/marble_wall.xpm
F 200,150,100
C 100,150,200
111111
100001
101001
1100N1
111111


In this example:
- `NO` refers to the texture for the North side of the wall.
- `F` and `C` set the floor and ceiling colors.
- `1` represents walls, `0` represents open space, and `N` shows where you start.

## 🎯 Goals

The goal of **cub3D** is to create a fun and visually engaging experience where you can navigate a maze in 3D. It’s not just about coding; it’s about bringing a piece of gaming history to life and having fun while doing it!

## 📝 How to Get Started

1. **Explore the Maze**: Use the arrow keys and W, A, S, D to move around.
2. **Customize**: Change textures and colors to make the maze your own.
3. **Have Fun**: Enjoy exploring your 3D maze and experimenting with different settings!

Enjoy your journey through the maze!


This `README.md` provides a clear and engaging overview of the cub3D project, designed to be accessible and interesting for non-technical users.
