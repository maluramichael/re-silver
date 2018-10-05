// Generated using ReClass 2016

class Player;
class N00000212;
class N00000246;
class N000003AE;
class N000003B1;
class N000003DD;
class N000003F1;
class N0000040E;
class N00000551;
class N00000654;
class Attack;
class N0000087B;
class N0000088E;
class N00000891;
class N00000894;
class N00000897;
class N0000089A;
class N0000089D;
class N000008AE;
class Character;
class N000008E5;
class N000008E8;
class N00000A7A;
class N00000A88;
class N00000A96;
class N00000AB1;
class N00000AB6;
class N00000AC9;
class N00000EFB;
class N0000130D;
class N00001426;

class Player
{
public:
	__int32 level; //0x0000 
	__int32 strength; //0x0004 
	__int32 dexterity; //0x0008 
	__int32 distanceAttack; //0x000C 
	__int32 wisdom; //0x0010 
	__int32 constitution; //0x0014 
	__int32 hp; //0x0018 
	__int32 mp; //0x001C 
	__int32 maxHp; //0x0020 
	__int32 maxMp; //0x0024 
	__int32 defense; //0x0028 
	char pad_0x002C[0x4]; //0x002C
	__int32 radiusOfGreenRing; //0x0030 
	__int32 speed; //0x0034 
	char pad_0x0038[0x90]; //0x0038
	__int32 hp; //0x00C8 
	__int32 mp; //0x00CC 
	char pad_0x00D0[0x50]; //0x00D0
	Character* target; //0x0120 
	Attack* currentAttack; //0x0124 
	char pad_0x0128[0x50]; //0x0128
	Vector3 N00000060; //0x0178 
	char pad_0x0184[0x58]; //0x0184
	Vector3 attackDestination; //0x01DC 
	char pad_0x01E8[0x8]; //0x01E8
	__int32 attackType; //0x01F0  1 == normal click attack 2 == attack with ctrl
	__int32 attackId; //0x01F4 
	char pad_0x01F8[0x2E0]; //0x01F8

}; //Size=0x04D8

class N00000212
{
public:
	char pad_0x0000[0x4]; //0x0000
	N000003AE* N00000214; //0x0004 
	N000003B1* N00000215; //0x0008 
	char pad_0x000C[0x18]; //0x000C
	char* N0000021D; //0x0024 
	char pad_0x0028[0x20]; //0x0028
	N00000246* N00000226; //0x0048 
	char pad_0x004C[0x800]; //0x004C

}; //Size=0x084C

class N00000246
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N000003AE
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N000003B1
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N000003DD
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N000003F1
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N0000040E
{
public:
	char pad_0x0000[0x8]; //0x0000
	N00000551* N00000411; //0x0008 
	char pad_0x000C[0x4F8]; //0x000C

}; //Size=0x0504

class N00000551
{
public:
	char pad_0x0000[0x404]; //0x0000

}; //Size=0x0404

class N00000654
{
public:
	char pad_0x0000[0x840]; //0x0000

}; //Size=0x0840

class Attack
{
public:
	__int32 id; //0x0000 
	char* name; //0x0004 
	char pad_0x0008[0x20]; //0x0008

}; //Size=0x0028

class N0000087B
{
public:
	char pad_0x0000[0x24]; //0x0000

}; //Size=0x0024

class N0000088E
{
public:
	char pad_0x0000[0x2C]; //0x0000

}; //Size=0x002C

class N00000891
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000894
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000897
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N0000089A
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N0000089D
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N000008AE
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class Character
{
public:
	char pad_0x0000[0x94]; //0x0000
	char* filePath; //0x0094 
	char pad_0x0098[0x48]; //0x0098

}; //Size=0x00E0

class N000008E5
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N000008E8
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N00000A7A
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000A88
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000A96
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000AB1
{
public:
	char pad_0x0000[0x4]; //0x0000

}; //Size=0x0004

class N00000AB6
{
public:
	char pad_0x0000[0x44]; //0x0000

}; //Size=0x0044

class N00000AC9
{
public:
	char pad_0x0000[0xC4]; //0x0000

}; //Size=0x00C4

class N00000EFB
{
public:
	char pad_0x0000[0xC74]; //0x0000
	N0000130D* N00001219; //0x0C74 
	char pad_0x0C78[0x3C8]; //0x0C78

}; //Size=0x1040

class N0000130D
{
public:
	char pad_0x0000[0xC4]; //0x0000

}; //Size=0x00C4

class N00001426
{
public:
	char pad_0x0000[0x504]; //0x0000

}; //Size=0x0504

