// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/haibian
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

��������Ƹ����񣬹²����С�׻����������Ϻ��ϵ�һ��С����
����Сȴ�����������˵�����������ڵ��ϴ���˵������ĿԶ����
�����ɼ���½��������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tingjing",
]));
  set("outdoors", "/d/nanhai");

  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me = this_player();
   
message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε��˴�½���ߡ�\n" NOR, me);
        me->move("/d/changan/southseashore");
   message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
   me->receive_damage("kee", 20);
   me->receive_damage("sen", 20);
        return 1;
}
