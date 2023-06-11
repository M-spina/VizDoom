
/*
    This file is autogenerated by scripts/create_python_docstrings_from_docs.py
    Do not edit it manually. Edit the Markdown files instead and regenerate it.
*/

#ifndef __VIZDOOM_DOCSTRINGS_H__
#define __VIZDOOM_DOCSTRINGS_H__

#include <string>

namespace vizdoom {
namespace docstrings {

namespace DoomGamePython {

    const std::string init = R"DOCSTRING(Initializes ViZDoom game instance and starts a new episode.
After calling this method, the first state from a new episode will be available.
Some configuration options cannot be changed after calling this method.
Init returns true when the game was started properly and false otherwise.)DOCSTRING";

    const std::string close = R"DOCSTRING(Closes ViZDoom game instance.
It is automatically invoked by the destructor.
The game can be initialized again after being closed.)DOCSTRING";

    const std::string newEpisode = R"DOCSTRING(Initializes a new episode. The state of an environment is completely restarted (all variables and rewards are reset to their initial values).
After calling this method, the first state from the new episode will be available.
If the `recordFilePath` is not empty, the new episode will be recorded to this file (as a Doom lump).

In a multiplayer game, the host can call this method to finish the game.
Then the rest of the players must also call this method to start a new episode.)DOCSTRING";

    const std::string replayEpisode = R"DOCSTRING(Replays a recorded episode from the given file using the perspective of the specified player.
Players are numbered from 1, `player` equal to 0 results in replaying the demo using the perspective of the default player in the recording file.
After calling this method, the first state from the replay will be available.
All rewards, variables, and states are available during the replaying episode.)DOCSTRING";

    const std::string isRunning = R"DOCSTRING(Checks if the ViZDoom game instance is running.)DOCSTRING";

    const std::string isMultiplayerGame = R"DOCSTRING(Checks if the game is in multiplayer mode.)DOCSTRING";

    const std::string isRecordingEpisode = R"DOCSTRING(Checks if the game is in recording mode.)DOCSTRING";

    const std::string isReplayingEpisode = R"DOCSTRING(Checks if the game is in replaying mode.)DOCSTRING";

    const std::string setAction = R"DOCSTRING(Sets the player's action for the next tics.
Each value corresponds to a button specified with [`addAvailableButton`](#addAvailableButton) method
or in the configuration file (in order of appearance).)DOCSTRING";

    const std::string advanceAction = R"DOCSTRING(Processes a specified number of tics. If `updateState` is set,
the state will be updated after the last processed tic and a new reward will be calculated.
To get the new state, use `getState` and to get the new reward use `getLastReward`.
If `updateState` is not set, the state will not be updated.)DOCSTRING";

    const std::string makeAction = R"DOCSTRING(Method combining usability of [`setAction`](#setAction), [`advanceAction`](#advanceAction) and [`getLastReward`](#getLastReward).
Sets the player's action for the next tics, processes a specified number of tics,
updates the state and calculates a new reward, which is returned.)DOCSTRING";

    const std::string isNewEpisode = R"DOCSTRING(Returns true if the current episode is in the initial state - the first state, no actions were performed yet.)DOCSTRING";

    const std::string isEpisodeFinished = R"DOCSTRING(Returns true if the current episode is in the terminal state (is finished).
[`makeAction`](#makeAction) and [`advanceAction`](#advanceAction) methods will take no effect after this point (unless [`newEpisode`](#newEpisode) method is called).)DOCSTRING";

    const std::string isPlayerDead = R"DOCSTRING(Returns true if the player is dead.
In singleplayer, the player's death is equivalent to the end of the episode.
In multiplayer, when the player is dead [`respawnPlayer`](#respawnPlayer) method can be called.)DOCSTRING";

    const std::string respawnPlayer = R"DOCSTRING(This method respawns the player after death in multiplayer mode.
After calling this method, the first state after the respawn will be available.)DOCSTRING";

    const std::string sendGameCommand = R"DOCSTRING(Sends the command to Doom console. It can be used for controlling the game, changing settings, cheats, etc.
Some commands will be blocked in some modes.)DOCSTRING";

    const std::string getState = R"DOCSTRING(Returns [`GameState`](Types.md#gamestate) object with the current game state.
If the current episode is finished, `nullptr/null/None` will be returned.)DOCSTRING";

    const std::string getServerState = R"DOCSTRING(Returns [`ServerState`](Types.md#serverstate) object with the current server state.)DOCSTRING";

    const std::string getLastAction = R"DOCSTRING(Returns the last action performed.
Each value corresponds to a button added with `[addAvailableButton](#addAvailableButton)` (in order of appearance).
Most useful in `SPECTATOR` mode.)DOCSTRING";

    const std::string getEpisodeTime = R"DOCSTRING(Returns number of current episode tic.)DOCSTRING";

    const std::string save = R"DOCSTRING(Saves a game's internal state to the file using ZDoom's save game functionality.)DOCSTRING";

    const std::string load = R"DOCSTRING(Loads a game's internal state from the file using ZDoom's load game functionality.
A new state is available after loading.
Loading the game state does not reset the current episode state,
tic counter/time and total reward state keep their values.


## <a name="buttons"></a> Buttons settings methods)DOCSTRING";

    const std::string getAvailableButtons = R"DOCSTRING(Returns the list of available `Buttons`.)DOCSTRING";

    const std::string setAvailableButtons = R"DOCSTRING(Set given list of `Button`s (e.g. `TURN_LEFT`, `MOVE_FORWARD`) as available `Buttons`,

Config key: `availableButtons/available_buttons` (list))DOCSTRING";

    const std::string addAvailableButton = R"DOCSTRING(Add [`Button`](Types.md#button) type (e.g. `TURN_LEFT`, `MOVE_FORWARD`) to available `Buttons` and sets the maximum allowed, absolute value for the specified button.
If the given button has already been added, it will not be added again, but the maximum value is overridden.

Config key: `availableButtons/available_buttons` (list))DOCSTRING";

    const std::string clearAvailableButtons = R"DOCSTRING(Clears all available `Buttons` added so far.)DOCSTRING";

    const std::string getAvailableButtonsSize = R"DOCSTRING(Returns the number of available `Buttons`.)DOCSTRING";

    const std::string setButtonMaxValue = R"DOCSTRING(Sets the maximum allowed absolute value for the specified button.
Setting the maximum value to 0 results in no constraint at all (infinity).
This method makes sense only for delta buttons.
The constraints limit applies in all Modes.)DOCSTRING";

    const std::string getButtonMaxValue = R"DOCSTRING(Returns the maximum allowed absolute value for the specified button.)DOCSTRING";

    const std::string getButton = R"DOCSTRING(Returns the current state of the specified button (`ATTACK`, `USE` etc.).



## <a name="vars"></a> GameVariables methods)DOCSTRING";

    const std::string getAvailableGameVariables = R"DOCSTRING(Returns the list of available `GameVariables`.)DOCSTRING";

    const std::string setAvailableGameVariables = R"DOCSTRING(Set list of [`GameVariable`](Types.md#gamevariable) as available `GameVariables` in the [`GameState`](Types.md#gamestate) returned by `getState` method.

Config key: `availableGameVariables/available_game_variables` (list))DOCSTRING";

    const std::string addAvailableGameVariable = R"DOCSTRING(Adds the specified [`GameVariable`](Types.md#gamevariable) to the list of available game variables (e.g. `HEALTH`, `AMMO1`, `ATTACK_READY`) in the [`GameState`](Types.md#gamestate) returned by `getState` method.

Config key: `availableGameVariables/available_game_variables` (list))DOCSTRING";

    const std::string clearAvailableGameVariables = R"DOCSTRING(Clears the list of available `GameVariables` that are included in the GameState returned by [`getState`](#getState) method.)DOCSTRING";

    const std::string getAvailableGameVariablesSize = R"DOCSTRING(Returns the number of available `GameVariables`.)DOCSTRING";

    const std::string getGameVariable = R"DOCSTRING(Returns the current value of the specified game variable (`HEALTH`, `AMMO1` etc.).
The specified game variable does not need to be among available game variables (included in the state).
It could be used for e.g. shaping. Returns 0 in case of not finding given `GameVariable`.



## <a name="args"></a> Game Arguments methods)DOCSTRING";

    const std::string addGameArgs = R"DOCSTRING(Adds a custom argument that will be passed to ViZDoom process during initialization.
Useful for changing additional game settings.

Config key: `gameArgs/game_args`)DOCSTRING";

    const std::string clearGameArgs = R"DOCSTRING(Clears all arguments previously added with [`addGameArgs`](#addGameArgs) method.


## <a name="rewards"></a> Reward methods)DOCSTRING";

    const std::string getLivingReward = R"DOCSTRING(Returns the reward granted to the player after every tic.)DOCSTRING";

    const std::string setLivingReward = R"DOCSTRING(Sets the reward granted to the player after every tic. A negative value is also allowed.

Default value: 0

Config key: `livingReward/living_reward`)DOCSTRING";

    const std::string getDeathPenalty = R"DOCSTRING(Returns the penalty for the player's death.)DOCSTRING";

    const std::string setDeathPenalty = R"DOCSTRING(Sets a penalty for the player's death. Note that in case of a negative value, the player will be rewarded upon dying.

Default value: 0

Config key: `deathPenalty/death_penalty`)DOCSTRING";

    const std::string getLastReward = R"DOCSTRING(Returns a reward granted after the last update of state.)DOCSTRING";

    const std::string getTotalReward = R"DOCSTRING(Returns the sum of all rewards gathered in the current episode.


## <a name="settings"></a> General game setting methods)DOCSTRING";

    const std::string loadConfig = R"DOCSTRING(Loads configuration (resolution, available buttons, game variables etc.) from a configuration file.
In case of multiple invocations, older configurations will be overwritten by the recent ones.
Overwriting does not involve resetting to default values. Thus only overlapping parameters will be changed.
The method returns true if the whole configuration file was correctly read and applied,
false if the file contained errors.)DOCSTRING";

    const std::string getMode = R"DOCSTRING(Returns current mode.)DOCSTRING";

    const std::string setMode = R"DOCSTRING(Sets mode (`PLAYER`, `SPECTATOR`, `ASYNC_PLAYER`, `ASYNC_SPECTATOR`) in which the game will be running.

Default value: `PLAYER`.

Config key: `mode`)DOCSTRING";

    const std::string getTicrate = R"DOCSTRING(Returns current ticrate.)DOCSTRING";

    const std::string setTicrate = R"DOCSTRING(Sets ticrate for ASNYC Modes - number of logic tics executed per second.
The default Doom ticrate is 35. This value will play a game at normal speed.

Default value: 35 (default Doom ticrate).

Config key: `ticrate`)DOCSTRING";

    const std::string setViZDoomPath = R"DOCSTRING(Sets path to the ViZDoom engine executable vizdoom.

Default value: "{vizdoom.so location}/{vizdoom or vizdoom.exe (on Windows)}".

Config key: `ViZDoomPath/vizdoom_path`)DOCSTRING";

    const std::string setDoomGamePath = R"DOCSTRING(Sets the path to the Doom engine based game file (wad format).
If not used DoomGame will look for doom2.wad and freedoom2.wad (in that order) in the directory of ViZDoom's installation (where vizdoom.so/pyd is).

Default value: "{vizdoom.so location}/{doom2.wad, doom.wad, freedoom2.wad or freedoom.wad}"

Config key: `DoomGamePath/doom_game_path`)DOCSTRING";

    const std::string setDoomScenarioPath = R"DOCSTRING(Sets the path to an additional scenario file (wad format).
If not provided, the default Doom single-player maps will be loaded.

Default value: ""

Config key: `DoomScenarioPath/set_doom_scenario_path`)DOCSTRING";

    const std::string setDoomMap = R"DOCSTRING(Sets the map name to be used.

Default value: "map01", if set to empty "map01" will be used.

Config key: `DoomMap/doom_map`)DOCSTRING";

    const std::string setDoomSkill = R"DOCSTRING(Sets Doom game difficulty level, which is called skill in Doom.
The higher the skill, the harder the game becomes.
Skill level affects monsters' aggressiveness, monsters' speed, weapon damage, ammunition quantities, etc.
Takes effect from the next episode.

- 1 - VERY EASY, “I'm Too Young to Die” in Doom.
- 2 - EASY, “Hey, Not Too Rough" in Doom.
- 3 - NORMAL, “Hurt Me Plenty” in Doom.
- 4 - HARD, “Ultra-Violence” in Doom.
- 5 - VERY HARD, “Nightmare!” in Doom.

Default value: 3

Config key: `DoomSkill/doom_skill`)DOCSTRING";

    const std::string setDoomConfigPath = R"DOCSTRING(Sets the path for ZDoom's configuration file.
The file is responsible for the configuration of the ZDoom engine itself.
If it does not exist, it will be created after the `vizdoom` executable is run.
This method is not needed for most of the tasks and is added for the convenience of users with hacking tendencies.

Default value: "", if left empty "_vizdoom.ini" will be used.

Config key: `DoomConfigPath/doom_config_path`)DOCSTRING";

    const std::string getSeed = R"DOCSTRING(Return ViZDoom's seed.)DOCSTRING";

    const std::string setSeed = R"DOCSTRING(Sets the seed of the ViZDoom's RNG that generates seeds (initial state) for episodes.

Default value: randomized in constructor

Config key: `seed`)DOCSTRING";

    const std::string getEpisodeStartTime = R"DOCSTRING(Returns start delay of every episode in tics.)DOCSTRING";

    const std::string setEpisodeStartTime = R"DOCSTRING(Sets start delay of every episode in tics.
Every episode will effectively start (from the user's perspective) after the provided number of tics.

Default value: 1

Config key: `episodeStartTime/episode_start_time`)DOCSTRING";

    const std::string getEpisodeTimeout = R"DOCSTRING(Returns the number of tics after which the episode will be finished.)DOCSTRING";

    const std::string setEpisodeTimeout = R"DOCSTRING(Sets the number of tics after which the episode will be finished. 0 will result in no timeout.

Config key: `episodeTimeout/episode_timeout`


## <a name="rendering"></a> Output/rendering setting methods)DOCSTRING";

    const std::string setScreenResolution = R"DOCSTRING(Sets the screen resolution. ZDoom engine supports only specific resolutions.
Supported resolutions are part of ScreenResolution enumeration (e.g., `RES_320X240`, `RES_640X480`, `RES_1920X1080`).
The buffers, as well as the content of ViZDoom's display window, will be affected.

Default value: `RES_320X240`

Config key: `screenResolution/screen_resolution`)DOCSTRING";

    const std::string getScreenFormat = R"DOCSTRING(Returns the format of the screen buffer and the automap buffer.)DOCSTRING";

    const std::string setScreenFormat = R"DOCSTRING(Sets the format of the screen buffer and the automap buffer.
Supported formats are defined in `ScreenFormat` enumeration type (e.g. `CRCGCB`, `RGB24`, `GRAY8`).
The format change affects only the buffers, so it will not have any effect on the content of ViZDoom's display window.

Default value: `CRCGCB`

Config key: `screenFormat/screen_format`)DOCSTRING";

    const std::string isDepthBufferEnabled = R"DOCSTRING(Returns true if the depth buffer is enabled.)DOCSTRING";

    const std::string setDepthBufferEnabled = R"DOCSTRING(Enables rendering of the depth buffer, it will be available in the state.
Depth buffer will contain noise if `viz_nocheat` is enabled.

Default value: false

Config key: `depthBufferEnabled/depth_buffer_enabled`)DOCSTRING";

    const std::string isLabelsBufferEnabled = R"DOCSTRING(Returns true if the labels buffer is enabled.)DOCSTRING";

    const std::string setLabelsBufferEnabled = R"DOCSTRING(Enables rendering of the labels buffer, it will be available in the state with the vector of `Label`s.
LabelsBuffer will contain noise if `viz_nocheat` is enabled.

Default value: false

Config key: `labelsBufferEnabled/labels_buffer_enabled`)DOCSTRING";

    const std::string isAutomapBufferEnabled = R"DOCSTRING(Returns true if the automap buffer is enabled.)DOCSTRING";

    const std::string setAutomapBufferEnabled = R"DOCSTRING(Enables rendering of the automap buffer, it will be available in the state.

Default value: false

Config key: `automapBufferEnabled/automap_buffer_enabled`)DOCSTRING";

    const std::string setAutomapMode = R"DOCSTRING(Sets the automap mode (`NORMAL`, `WHOLE`, `OBJECTS`, `OBJECTS_WITH_SIZE`),
which determines what will be visible on it.

Default value: `NORMAL`

Config key: `automapMode/set_automap_mode`)DOCSTRING";

    const std::string setAutomapRotate = R"DOCSTRING(Determine if the automap will be rotating with the player.
If false, north always will be at the top of the buffer.

Default value: false

Config key: `automapRotate/automap_rotate`)DOCSTRING";

    const std::string setAutomapRenderTextures = R"DOCSTRING(Determine if the automap will be textured, showing the floor textures.

Default value: true

Config key: `automapRenderTextures/automap_render_textures`)DOCSTRING";

    const std::string setRenderHud = R"DOCSTRING(Determine if the hud will be rendered in the game.

Default value: false

Config key: `renderHud/render_hud`)DOCSTRING";

    const std::string setRenderMinimalHud = R"DOCSTRING(Determine if the minimalistic version of the hud will be rendered instead of the full hud.

Default value: false

Config key: `renderMinimalHud/render_minimal_hud`)DOCSTRING";

    const std::string setRenderWeapon = R"DOCSTRING(Determine if the weapon held by the player will be rendered in the game.

Default value: true

Config key: `renderWeapon/render_weapon`)DOCSTRING";

    const std::string setRenderCrosshair = R"DOCSTRING(Determine if the crosshair will be rendered in the game.

Default value: false

Config key: `renderCrosshair/render_crosshair`)DOCSTRING";

    const std::string setRenderDecals = R"DOCSTRING(Determine if the decals (marks on the walls) will be rendered in the game.

Default value: true

Config key: `renderDecals/render_decals`)DOCSTRING";

    const std::string setRenderParticles = R"DOCSTRING(Determine if the particles will be rendered in the game.

Default value: true

Config key: `renderParticles/render_particles`)DOCSTRING";

    const std::string setRenderEffectsSprites = R"DOCSTRING(Determine if some effects sprites (gun puffs, blood splats etc.) will be rendered in the game.

Default value: true

Config key: `renderEffectsSprites/render_effects_sprites`)DOCSTRING";

    const std::string setRenderMessages = R"DOCSTRING(Determine if in-game messages (information about pickups, kills, etc.) will be rendered in the game.

Default value: false

Config key: `renderMessages/render_messages`)DOCSTRING";

    const std::string setRenderCorpses = R"DOCSTRING(Determine if actors' corpses will be rendered in the game.

Default value: true

Config key: `renderCorpses/render_corpses`)DOCSTRING";

    const std::string setRenderScreenFlashes = R"DOCSTRING(Determine if the screen flash effect upon taking damage or picking up items will be rendered in the game.

Default value: true

Config key: `renderScreenFlashes/render_screen_flashes`)DOCSTRING";

    const std::string setRenderAllFrames = R"DOCSTRING(Determine if all frames between states will be rendered (when skip greater than 1 is used).
Allows smooth preview but can reduce performance.
It only makes sense to use it if the window is visible.

Default value: false

Config key: `renderAllFrames/render_all_frames`)DOCSTRING";

    const std::string setWindowVisible = R"DOCSTRING(Determines if ViZDoom's window will be visible.
ViZDoom with window disabled can be used on Linux systems without X Server.

Default value: false

Config key: `windowVisible/window_visible`)DOCSTRING";

    const std::string setConsoleEnabled = R"DOCSTRING(Determines if ViZDoom's console output will be enabled.

Default value: false

Config key: `consoleEnabled/console_enabled`)DOCSTRING";

    const std::string setSoundEnabled = R"DOCSTRING(Determines if ViZDoom's sound will be played.

Default value: false

Config key: `soundEnabled/sound_enabled`)DOCSTRING";

    const std::string getScreenWidth = R"DOCSTRING(Returns game's screen width - width of all buffers.)DOCSTRING";

    const std::string getScreenHeight = R"DOCSTRING(Returns game's screen height - height of all buffers.)DOCSTRING";

    const std::string getScreenChannels = R"DOCSTRING(Returns number of channels in screen buffer and map buffer (depth and labels buffer always have one channel).)DOCSTRING";

    const std::string getScreenPitch = R"DOCSTRING(Returns size in bytes of one row in screen buffer and map buffer.)DOCSTRING";

    const std::string getScreenSize = R"DOCSTRING(Returns size in bytes of screen buffer and map buffer.)DOCSTRING";

    const std::string isObjectsInfoEnabled = R"DOCSTRING(Returns true if the objects information is enabled.)DOCSTRING";

    const std::string setObjectsInfoEnabled = R"DOCSTRING(Enables information about all objects present in the current episode/level.
It will be available in the state.

Default value: false

Config key: `objectsInfoEnabled/objects_info_enabled`)DOCSTRING";

    const std::string isSectorsInfoEnabled = R"DOCSTRING(Returns true if the information about sectors is enabled.)DOCSTRING";

    const std::string setSectorsInfoEnabled = R"DOCSTRING(Enables information about all sectors (map layout) present in the current episode/level.
It will be available in the state.

Default value: false

Config key: `sectorsInfoEnabled/sectors_info_enabled`)DOCSTRING";

    const std::string isAudioBufferEnabled = R"DOCSTRING(Returns true if the audio buffer is enabled.)DOCSTRING";

    const std::string setAudioBufferEnabled = R"DOCSTRING(Returns true if the audio buffer is enabled.

Default value: false

Config key: `audioBufferEnabled/audio_buffer_enabled`)DOCSTRING";

    const std::string getAudioSampliongRate = R"DOCSTRING(Returns the sampling rate of the audio buffer.)DOCSTRING";

    const std::string setAudioSamplingRate = R"DOCSTRING(Sets the sampling rate of the audio buffer.

Default value: false

Config key: `audioSamplingRate/audio_samping_rate`)DOCSTRING";

    const std::string getAudioBufferSize = R"DOCSTRING(Returns the size of the audio buffer.)DOCSTRING";

    const std::string setAudioBufferSize = R"DOCSTRING()DOCSTRING";

} // namespace DoomGamePython

    const std::string doomTicsToMs = R"DOCSTRING(Calculates how many tics will be made during given number of milliseconds.)DOCSTRING";

    const std::string msToDoomTics = R"DOCSTRING(Calculates the number of milliseconds that will pass during specified number of tics.)DOCSTRING";

    const std::string doomTicsToSec = R"DOCSTRING(Calculates how many tics will be made during given number of seconds.)DOCSTRING";

    const std::string secToDoomTics = R"DOCSTRING(Calculates the number of seconds that will pass during specified number of tics.)DOCSTRING";

    const std::string doomFixedToDouble = R"DOCSTRING(Converts Doom's fixed point numeral to a floating point value.

- Types: `User variables` in `GameVariables`

Python aliases (added in 1.1):
`float doom_fixed_to_float(int / float doomFixed)`)DOCSTRING";

    const std::string isBinaryButton = R"DOCSTRING(Returns true if button is binary button.)DOCSTRING";

    const std::string isDeltaButton = R"DOCSTRING()DOCSTRING";


} // namespace docstrings
} // namespace vizdoom
#endif
