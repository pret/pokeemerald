
# Quickstart

Quickstart is a developer convenience feature that allows the user to start a new game from the title screen, skipping the Main Menu and the Birch/Oak intros. In Emerald the player is immediately dropped into the opening truck sequence while in FRLG the player is warped straight into their room.

> **NOTE:** Quickstart is a development only feature and is therefore automatically disabled on release builds.

## Details

Quickstart is enabled by default. It can be turned off using the provided configuration option. It is automatically disabled in release builds.

To use Quickstart press `SELECT` from the title screen to immediately start a new game. The player's name is set to the English canon name (and in FRLG the rival as well). The player's gender is chosen randomly (this can be configured).

#### Player Names

| Game | Male | Female |
| --------------- | --------------- | --------------- |
| **Emerald** | BRENDAN | MAY |
| **FRLG** | RED | LEAF |

The FRLG Rival is named **BLUE**.

#### Hud Element

When Quickstart is enabled a small HUD element is shown on the title screen (this can be disabled). This is displayed as a `64x32` sprite at the top-right corner of the screen. The image dimensions are only `64x16` however but the GBA does not support sprites of those dimensions.

**Source File** : `graphics/quickstart/quickstart_hud.png`

![Quickstart HUD](https://i.ibb.co/G4hhwvmy/quickstart-hud.png)

The same sprite is used for Fire Red, Leaf Green and Emerald. Each game has it's own palette in the `graphics/quickstart/` directory.

## Configuration

The configuration options are briefly covered below.

| Option              | Values                                      | Usage |
|--------------------|---------------------------------------------|------- |
| **`ENABLE_QUICKSTART`**  | `TRUE` / `FALSE` | Enables quickstart in dev builds.<br>Always disabled in release builds. |
| **`QUICKSTART_HUD`**     | `TRUE` / `FALSE`| Shows a small HUD when quickstart is enabled. No effect otherwise. |
| **`QUICKSTART_GENDER`**  | `GENDER_MALE`, `GENDER_FEMALE`, `GENDER_RANDOM` | Sets player gender for quickstart.<br>`RANDOM` = 50% chance for `MALE`/`FEMALE`. |
| **`QUICKSTART_HUD_X`**<br>**`QUICKSTART_HUD_Y`**| `s16 Coordinates` | X & Y Coordinate for the HUD element sprite |

## Public Functions

The interface of the Quickstart feature has been kept minimal. It exposes only two functions.

#### `CreateQuickstartHud`

```c
void CreateQuickstartHud(void);
```

```
Initializes and places a small HUD element on screen. Coordinates specifed in config
Only has an effect when quickstart is enabled.

```

#### `Quickstart`

```c
void Quickstart(void);
```

```
Starts a new game from the title screen when called.
```

## Integration

The aforementioned functions may be of use for integrating this feature into custom title screens. Adding calls to the appropriate function gated with a check should suffice.

```c
// For the HUD
if (QUICKSTART && QUICKSTART_HUD)
  CreateQuickstartHud();
```

```
// To trigger Quickstart
if (QUICKSTART && JOY_NEW(SELECT_BUTTON))
    Quickstart();
```
