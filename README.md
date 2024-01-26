# Graphene

QMK implementation of the [Graphite layout](https://github.com/rdavison/graphite-layout) with some additional magic inspired by [Magic Sturdy](https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md).

The layout was initially [generated by Oryx](https://configure.zsa.io/voyager/layouts/vr7YO) but then heavily modified in code to make it up-to-date with QMK 0.22 and also easier to maintain. It builds on a [QMK Pull Request for ZSA Voyager](https://github.com/qmk/qmk_firmware/pull/22181) which as of this writing hasn't been merged back to QMK but according to my testing is functional.

## The Layout

```
  1 2 3 4 5      6 7 8 9 0
` B L D W Z      ❖ F O U J ;
  N R T S G      Y H A E I ⏎
= Q X M C V      K P ' , . /
         ␣ ⇥    ® ␈
```

The layout has been designed in a way that makes it easy to use with just 34 keys. The top row and the outer columns can be ignored as their keycodes also exist on other layers.

## Magic & Repeat

> [!NOTE]
> The magic key `❖` is on the right index finger and the repeat key `®` is on the right thumb.

The magic and repeat keys are a customized version of QMK's [Repeat Key](https://docs.qmk.fm/#/feature_repeat_key) feature. They both dynamically adjust their output based on the most recent keycode. Their primary function in Graphene is to improve typing bigrams that are more difficult to type in Graphite but still fairly frequent in English texts. This is further extended with common n-grams.

The mappings in Graphene draw heavily from the choices in [Magic Sturdy](https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md) but adapted to the Graphite layout.

### Magic Key Mappings

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `A` | `B`      | `C` | `D` | `E` | `F` | `G` | `H` | `I`  | `J`   | `K` | `L`     | `M`   |
| Magic | `O` | `EFORE`  | `S` | `M` | `U` | --  | `S` | `L` | `ON` | `UST` | `J` | `ATION` | `ENT` |


|     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `N`   | `O` | `P` | `Q`    | `R` | `S` | `T`   | `U` | `V`  | `W`   | `X`    | `Y` | `Z` |
| Magic | `ING` | `A` | --  | `UEST` | `L` | `Z` | `ION` | `E` | `ER` | `ITH` | `PERI` | --  | `S` |

|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prev  | `wspc` | `,`    | `.` | `/` | `-` | `=` | `<` | `>` |
| Magic | `THE`  | `⎵BUT` | `\` | --  | `>` | `>` | `=` | `=` |

A second press of the `magic` key outputs `N`, regardless of the previous key. `wspc` stands for "white space" and includes `space`, `tab`, `enter`, `"`, and `(`.

### Repeat Key Overrides

The `repeat` key simply repeats the previous key (e.g. `L` `repeat` outputs `L` `L`) with the following exceptions:

| Prev | Repeat |
| --- | --- |
| `A` | `ND` |
| `I` | `NG` |
| `Y` | `OU` then `'` then `ll` |
| `N` | `F` |
| `B` | `ECAUSE` |
| `W` | `OULD` |
| `wspc` | `FOR` |
| `,` | `⎵AND` |
| `.?!:;` | `⎵` + oneshot `Shift` |

### More magic

There are two more magic keys which are mapped to combo keys. All combo keys fall on the lower row and mapped the following way:

* left index and middle fingers (`C` + `M`) => `:`
* right index and middle fingers (`P` + `'`) => `;`
* middle and ring fingers (`M` + `X` or `'` + `,`) => Magic Key 2
* ring and pinky fingers (`X` + `Q` or `,` + `.`) => Magic Key 3
* index and ring fingers (`C` + `X` or `P` + `,`) => `'s`

#### Magic Key 2 macros

* **`a`** `lready`
* **`b`** `ecome`
* **`c`** `ould`
* **`d`** `evelop`
* **`e`** `'ll`
* **`f`** `ollow`
* **`g`** `eneral`
* **`h`** `owever`
* **`i`** `'ll`
* **`j`** `udge`
* **`k`** `now`
* **`l`** `ittle`
* **`m`** `ight`
* **`n`** `eighbor`
* **`o`** `ther`
* **`p`** `sych`
* **`r`** `ight`
* **`s`** `hould`
* **`t`** `hough`
* **`u`** `pgrade`
* **`y`** `'ll`
* **`w`** `here`
* **`.`** `org`
* **`,`** ` however`

#### Magic Key 3 macros

* **`b`** `etween`
* **`n`** `umber`
* **`u`** `pdate`
* **`a`** `bout`
* **`w`** `orld`
* **`g`** `overn`
* **`p`** `rogram`
* **`q`** `uestion`
* **`c`** `rowd`
* **`s`** `chool`
* **`t`** `hrough`
* **`m`** `anage`
* **`o`** `xygen`
* **`i`** `'m`
* **`e`** `'re`
* **`.`** `com`
* **`,`** ` since`

## QMK Implementation

This implementation of the Graphite keymap is for a ZSA Voyager, but the code can be adapted to any keyboard.

See the [Oryx compatible version of the layout](https://configure.zsa.io/voyager/layouts/vr7YO) for a visual representation. Notable features of this implementation in addition to everything mentioned above:

* Layers:
  1. Navigation, Media keys, RGB control
  2. Symbols A
  3. Symbols B
  4. Numbers (top row _and_ numpad) and window management shortcuts (work with my Hammerspoon configuration)
* Tap-Hold keys for layers on home row and mods on top row
* Hold `Tab` and `Repeat` keys for `Shift`
* Hold `Space` key for `Hyper`
* Hold `Backspace` key for Layer 1 (for single hand navigation)
* Custom key for setting and restoring a favourite RGB animation
  * `B` key on second layer
  * combine with `Ctrl` to remember current animation
  * combine with `Shift` to reset to builtin default (typing heatmap)
  * otherwise set animation to what was last set with `Ctrl`