# ShooterSam

ShooterSam is a third-person shooter prototype built with Unreal Engine 5.6. It combines C++ gameplay code with Blueprint-authored characters, weapons, UI, AI, and levels.

![ShooterSam gameplay](assets/samshooter.gif)

## Highlights

- Third-person character movement, camera control, jumping, shooting, health, and damage feedback.
- Rifle gameplay with firing, impact, and reload assets.
- Enemy AI driven by Behavior Trees, Blackboard data, and custom C++ behavior tasks/services.
- Playable prototype levels in `Content/MyStuff/Maps`.
- Unreal Engine template variants and supporting assets included under `Content` and `Source`.

## Requirements

- Unreal Engine 5.6
- Visual Studio with the C++ desktop game-development workload

## Getting started

1. Clone the repository, including Git LFS files:

   ```bash
   git clone https://github.com/o-hesham/ShooterSam.git
   cd ShooterSam
   git lfs pull
   ```

2. Open `ShooterSam.uproject` in Unreal Editor.
3. Allow Unreal Engine to generate project files and compile the C++ module if prompted.
4. Open a map from `Content/MyStuff/Maps` and press **Play**.

## Project layout

| Path | Description |
| --- | --- |
| `Content/` | Unreal assets, Blueprints, maps, materials, animations, audio, and UI |
| `Source/ShooterSam/` | C++ gameplay, weapon, character, HUD, and AI code |
| `Config/` | Unreal Engine project configuration |
| `ShooterSam.uproject` | Unreal Engine project descriptor |

## Notes

Generated Unreal Engine folders such as `Binaries`, `Intermediate`, `Saved`, and `DerivedDataCache` are excluded from version control. The gameplay GIF is stored with Git LFS because it exceeds GitHub's regular per-file size limit.
