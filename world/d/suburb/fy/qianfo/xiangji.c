// 
// 

#include <room.h>
inherit ROOM;
int close_path();
void create()
{
  set("short","�����");
  set("long",@LONG
�����Ϊ���µĳ������������������������ഫ���Ի�Ϊһ��
ͷɮ�������߹���ɢ�������ķ��¡�
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang4.c",
            "west" :__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  setup();
}

void init()
{
add_action("do_push","push");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ�ƿ�ʲô��\n");
                return 1;
        }
        if( arg == "luowang" || arg == "���������" || arg == "����")
        {
        me = this_player();
        message_vision("$N�ƿ������������������һ���ܵ���\n", me);
        if( !query("exits/north") ) {
        set("exits/north", __DIR__"changlang4");
        call_out("close_path", 5);
        }
        return 1;
        }
        else
        {
                write("��������"+arg+"��\n");
                return 1;
        }
}
int close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"�����������ת�˻�������ס���򱱵�·��\n",
                this_object() );
                delete("exits/north");
}
