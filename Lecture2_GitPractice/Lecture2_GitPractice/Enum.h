#pragma once
#pragma region Enum

enum class SCENE_TYPE { TEST, START, LOBBY, FIELD, RAID, SHOP, JOB_CHANGE, BLACK_SMITH, EXIT, END };
enum class PLAYER_JOB { BEGINNER, WARRIOR, WIZARD, ARCHER, ASSASIN, END };
const char	STR_JOB_NAME[(int)PLAYER_JOB::END][10] = { "초보자", "전사", "마법사","궁수","도적" };

enum class OBJECT_TYPE { PLAYER, MONSTER, BOSS, PORTAL, UI, END };
enum class MONSTER_TYPE { ORANGE_MUSHROOM, SLIME, BOSS, END };
enum class BOSS_TYPE { MUSHMOM, BANBAN, PINK_BEAN, LUCID };

enum class PROPERTY_TYPE { NORMAL, FIRE, WATER, THUNDER, GROUND, ICE, END };
enum class STATE { NORMAL, BURN, WET, FROZEN, END };

enum class LOBBY_MENU { PLAYER_INFO = 1, PLAYER_INVENTORY, PLAYER_EQUIPMENT, FIELD, RAID, SHOP, JOB_CHANGE, BLACK_SMITH, SAVE, LOAD, EXIT, END, HIDDEN = 999 };
enum class SHOP_LEVEL { BEGGINER, MIDDLE, SENIOR, END };

enum class COLOR_TYPE {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_PURPLE,
	DARD_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE
};

enum class ITEM_TYPE { EQUIPMENT, CONSUMPTION, ETC, END };
enum class ITEM_COMBINE { COMBINED, UNCOMBINED };
enum class ITEM_CODE
{
	HP_POTION,
	MP_POTION,
	POWER_ELIXIR,
	PANACEA,
	BROWN_RADDER_HAT,
	WHITE_TEE,
	BASIC_JEAN,
	BASIC_CLUB,
	ZAQQUM_HAT,
	PENSALIR_ARMOR,
	PENSALIR_BOTTOM,
	PENSALIR_TWOHAND_SWORD,
	FAFNIR_HAT,
	FAFNIR_TOP,
	FAFNIR_BOTTOM,
	FAFNIR_TWOHANDSWORD,
	ENCHANT_ROCK,
	END
};
enum class ITEM_RARITY { NORMAL, RARE, EPIC, UNIQUE, LEGENDARY, END };
enum class EQUIP_TYPE { HAT, TOP, BOTTOM, WEAPON, NONEQUIP, END };
#pragma endregion Enum