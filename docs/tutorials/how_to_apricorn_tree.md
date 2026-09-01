# How to interact with Apricorn Trees

![apricorn-tree](/docs/tutorials/img/apricorn_tree/apricorn-tree.gif)

### Adding a new apricorn tree

To add a new tree, first increase the tree count and expand the tree list in `include/constants/apricorn_tree.h`.

Note that each tree will take a bit in the savegame's `SaveBlock3` struct so increasing `APRICORN_TREE_COUNT` **breaks the savegame**.
Due to this, pokeemerald-expansion doesn't have any trees set up by default to prevent breaking downstream savegames.
The trees support random yields and properly use plural case on plural yields.

```diff
#define APRICORN_TREE_NONE 0

-#define APRICORN_TREE_COUNT 0
+#define APRICORN_TREE_ROUTE101_RED_TREE 1
+
+#define APRICORN_TREE_COUNT 32
```

Then list its data in `src/data/apricorns.h`.

```diff
const struct ApricornTree gApricornTrees[APRICORN_TREE_COUNT] =
{
    [APRICORN_TREE_NONE] =
    {
        .minimum = 1,
        .maximum = 1,
        .apricornType = APRICORN_RED,
    },

+   [APRICORN_TREE_ROUTE101_RED_TREE] =
+   {
+       .minimum = 1,
+       .maximum = 1,
+       .apricornType = APRICORN_RED,
+   },
};
```
Finally, just place your new tree using Porymap.
Similarly to berries, the Sight Radius / Berry Tree ID field is used for the tree's ID.

![apricorn-tree-porymap](/docs/tutorials/img/apricorn_tree/apricorn-tree-porymap.png)

### Add a new apricorn type

After you created your new item, simply expand the `ApricornType` enum in `include/constants/apricorn_tree.h`.

```diff
enum ApricornType
{
    [...]
    APRICORN_BERRY_MARANGA = ITEM_MARANGA_BERRY,
+    APRICORN_BROWN         = ITEM_BROWN_APRICORN,
};
```
