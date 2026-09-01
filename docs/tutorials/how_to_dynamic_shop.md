# How to Use Dynamic Shop

## Overview

![Showcase](/docs/tutorials/img/dynamic_shop/showcase.gif)

This is a feature for the Shop Menu to allow developers to have a shop with automagically added items based off a certain Criteria. In the core series games, items are gated behind badge progression - this feature allows for that an further expands it to gate items based on any criteria the developer wants.

## Usage

To use this feature, simply use `pokemart` as you normally do. The real Sauce will be the Criterias that the items would get filtered on, as all items are added by Expansion's default.
```
MartScript::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
```
You can also use it without any arguments to instead use `Pokemart_DefaultItemList` in `data/scripts/mart_clerk.inc`, useful for general pokemart shops.

## What is a Criteria?

Criteria is the meat that helps the code automagically add items based on your feeded items list. By default, all items are added regardless to not break existing shops. This prevents unintended items from appearing.

Internally, a Criteria is actually a *function* that returns either `TRUE` or `FALSE` depending if a criteria is fulfilled.

## Adding Criteria to an Item

Adding a Criteria to an Item is simple enough, you'd just add the fields at the bottom of an item's data:
```diff
     [ITEM_POKE_BALL] =
     {
         .name = ITEM_NAME("Poké Ball"),
         .price = 200,
         .description = COMPOUND_STRING(
             "A tool used for\n"
             "catching wild\n"
             "Pokémon."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_POKE,
         .iconPic = gItemIcon_PokeBall,
         .iconPalette = gItemIconPalette_PokeBall,
+        .shopCriteriaFunc = <func>,
     },
```

Below are extra helper functions for the average usecases. They're not meant to be directly used as the Criteria function itself, only for the actual Criteria function you're making. Be sure to remove the `UNUSED` label from the function you're using after.

### `ShopCriteriaByBadgeCount`
This function is what you'll probably be using the most. You must provide one argument containing a number of total badges the player must own.
Example:
```
bool32 ShopCriteriaByTwoBadges(enum Item item)
{
    return ShopCriteriaByBadgeCount(2);
}
```

### `ShopCriteriaByFlag`
This function is basically what `BadgeCount` partially do, but you'd explicitly use one flag instead. Useful if you need a certain badge flag instead of just the _total amount_ of badges, or a quest-only item. You must provide one argument for the flag id you want, the flag ids found in [`include/constants/flags.h`](/include/constants/flags.h), like `FLAG_BADGE07_GET`. This function will returns `TRUE`/`FALSE` depending on if the flag is set or not.
Example:
```
bool32 ShopCriteriaByChampionFlag(enum Item item)
{
    return ShopCriteriaByFlag(FLAG_IS_CHAMPION);
}
```

### `ShopCriteriaByVar`
This function is basically the `Flag` function but with variables instead. You must provide both the variable id found in [`include/constants/vars.h`](/include/constants/vars.h) and a value to compare with said variable id as the arguments.
Example:
```
bool32 ShopCriteriaBySpecificValueInSpecificVar(enum Item item)
{
    return ShopCriteriaByVar(VAR_ASH_GATHER_COUNT, 20);
}
```

## Create a Custom Criteria

First, add a new function for your criteria in [`src/shop_criteria.c`](/src/shop_criteria.c), preferably after the `// Add new Criterias below!` comment, like so:
```diff
 // Add new Criterias below!
+bool32 ShopCriteriaByMyNeed(enum Item item)
+{
+    // add your stuff here, be sure to handle both `TRUE`/`FALSE` return values!
+}
```

Then, you'll need to add a declaration for your custom function so that it can be used by your items.
```diff
 // Add new Criterias below!
+bool32 ShopCriteriaByMyNeed(enum Item item);

 #endif // GUARD_SHOP_CRITERIA_H
```

And that's it! You should now be good to go and can immediately use that function for your items.
```diff
     [ITEM_POKE_BALL] =
     {
         .name = ITEM_NAME("Poké Ball"),
         .price = 200,
         .description = COMPOUND_STRING(
             "A tool used for\n"
             "catching wild\n"
             "Pokémon."),
         .pocket = POCKET_POKE_BALLS,
         .type = ITEM_USE_BAG_MENU,
         .battleUsage = EFFECT_ITEM_THROW_BALL,
         .secondaryId = BALL_POKE,
         .iconPic = gItemIcon_PokeBall,
         .iconPalette = gItemIconPalette_PokeBall,
+        .shopCriteriaFunc = ShopCriteriaByMyNeed,
     },
```

### Specific Example

We want to allow the player to purchase the Light Ball, but only after they have already captured Pikachu and defeated Wattson's final rematch.

#### [`src/shop_criteria.c`](/src/shop_criteria.c)
```diff
 // Add new Criterias below!
+bool32 ShopCriteriaHasPikachu(enum Item item)
+{
+    if (FlagGet(TRAINER_FLAGS_START + WATTSON_5) == FALSE)
+        return FALSE;
+
+    return (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_PIKACHU), FLAG_GET_CAUGHT));
+}
```

#### [`include/shop_criteria.h`](/include/shop_criteria.h)
```diff
 // Add new Criterias below!
+bool32 ShopCriteriaHasPikachu(enum Item item);
```

#### [`src/data/items`](/src/data/items.c)
```diff
     [ITEM_LIGHT_BALL] =
     {
         .name = ITEM_NAME("Light Ball"),
         .price = (I_PRICE >= GEN_7) ? 1000 : 100,
         .holdEffect = HOLD_EFFECT_LIGHT_BALL,
         .description = COMPOUND_STRING(
                 "A hold item that\n"
                 "raises the Atk and\n"
                 "Sp. Atk of Pikachu."),
         .pocket = POCKET_ITEMS,
         .sortType = ITEM_TYPE_HELD_ITEM,
         .type = ITEM_USE_BAG_MENU,
         .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
         .flingPower = 30,
         .iconPic = gItemIcon_LightBall,
         .iconPalette = gItemIconPalette_LightBall,
+        .shopCriteriaFunc = ShopCriteriaHasPikachu,
      },
```
