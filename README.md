
# Wolfenstein3D
![Wolfenstein3D](wolf3d.gif)
## Subject

"This project involves creating a first-person view inside a maze. You will have to program this perspective view as well as the movement of the camera on the map. The drawing principle that you must employ is raycasting.
To do this, you will need to be able to load map files containing one or more labyrinths, a starting position, and the locations of various game elements.
You are free to use any map format. However, we encourage you to design a unique format that allows for easy map exchange.
The player must be able to move in real time on the map using the keyboard.
The color of the walls should vary depending on their orientation or have a texture."


## Requirements

### MUST

#### General
- [x] The window may be **closed using events**.
- [x] The windows may have **differents mode**:
- Window mode
- Full - screen mode
- [x] The game manages **inputs from the mouse click and keyboard**.
- [x] The game contains **animated sprites** rendered thanks to **sprite sheets**.
- [x] Animations in your program are **frame rate independent**.
- [x] Animations and movements in your program are **timed by clocks**.

#### Gameplay and mechanics
- [x] **Movement**: Basic movements (forward, backward, left and right).
- [x] **First person** : First-person perspective.
- [x] **Textures and sprites** : Use of textures and sprites for objects.
- [x] **Light** (flashlight).
- [x] **A basic weapon** (knife or pistol): possibility to hit the walls without enemies, enemies are NOT a MUST feature.
- [x] **Save system**.

#### Environment
- [x] **Environment display** (floor, ceiling and walls).
- [x] **Collision** system.

#### Sounds and Graphics
- [x] At least one **animation**: Movement, shots, enemies etc.
- [x] **Sound effects and music**: Sounds and music to enhance the gaming experience.
- [ ] **Particle effects**: Use particles for explosions, shots, etc

#### User interface
- [x] **HUD**: Interface displaying essential information such as health, ammunition, etc.
- [x] **Options and Settings**
- [x] The main menu must contain:
- **Start the game**
- **Settings** : volumes and windows
- [x] **Leave** the game
- [x] **Volume options**: for sound and music.
- [x] **Window resolution options**: for sound and music.

### SHOULD

- [ ] **Weapons**: Several weapons ranging from knife to missile launcher, through machine guns.
- [x] **Map or mini map**: Display of the level map to help navigation.
- [x] **Procedural Labyrinthine Levels**: Procedural generation of levels with walls, doors, floor, ceiling.
- [x] **Various enemies**: Different types of enemies with distinct behaviors.
- [ ] **Inventory**: Interface to manage the collected items.
- [ ] **Localized Damage System**: Different damage based on the affected areas on enemies.
- [x] **Health system**: Player’s health indicator.
- [ ] **Ammunition**: Ammunition management for each weapon.
- [ ] **Doors and secrets**: Locked doors requiring keys, hidden walls with secrets.
- [ ] **Collectibles**: Treasures, keys and other collectibles.
- [ ] **Environmental Interactions**: For example, firing on explosive barrels or triggering traps

### COULD

- [ ] **Ladder management for different floors**: Mechanical to move between different levels.
- [ ] **Advanced health system**: Understand health effects such as bleeding or bandages.
- [ ] **Special weapons**: Unique weapons with special effects.
- [ ] **Dynamic Weather**: Integrate changing weather conditions affecting visibility and gameplay.
- [ ] **Difficulty levels**: Different difficulty levels adjusting the game settings.
- [ ] **Score and time**: Scoring and timing system to measure player performance.
- [ ] **Destructible environment**: Elements of the decor that can be destroyed or modified.
- [ ] **More complex shapes**: display and manage shapes other than squares.
- [x] Have a **map editor**.

///////////////////////////////

### PERSONAL BONUSES
- Certain ennemies give you back health.
- You can choose how to shoot (centered or with a visor following your mouse).

## MAP
The map file contains all the information about the map simulation.
Below is a example of a map file.

**Walls** are described by **1**
**Empty spaces** are described by **0**
Your map **must** be closed by walls

> #### ~/my_radar> cat example.txt
> 11111111111111111111111
>
> 10000000111101111100001
>
> 10000000000000000000111
>
> 10000000111111100000111
>
> 11111111111111111111111

### USAGE
>	./my_radar [OPTIONS]
>
### OPTIONS
>	-h	print the help menu.
>
>	-f path_to_file use the map in file (path_to_file is the path to the file file).
>
### USER INTERACTIONS
> 'esc'              key pause the simulation and put you in settings menu / come back in game.▶️⚙️
>
> 'Z’/'Q’/'S’/'D’    key to move forward/right/backward/left in order.🚶🚶‍♀️‍➡️
>
> ‘←’/‘→’            key to move view angle.👁️
>
> 'L'                key to put some light on.🔦
>
> 'Left mouse click' key to shoot.🔫
>
## Installation

If you haven't installed csfml yet, run:

    ./install-csfml.sh
Then run:

    make
And finally:

    ./wolf3d [-h, -f <map>]
Be carefull:

    We use big spritesheets and some computer might not allow them (size limitation) ! 😢
