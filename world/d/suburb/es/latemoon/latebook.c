
inherit ROOM;

void create()
{
      set("short","��Ժ�鷿");
	set("long", @LONG
����һ��СС���鷿���������������ص��ţ�һ�Ź��ⰻȻ�ĺ�ľ������
���������Ŀ�⣬�������һ��СС����¯�������Ʊ�������Ķѷ�������
���ɼ������൱�İ�ϧ�鱾��һ�����׺�������������ͼ������ǽ�ϣ��ƺ�
��һЩ��������ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"latemoon7",

        ]) );
        set("item_desc", ([
                "dragon-dance" : @TEXT
����һ������Ĳ�ͼ�����м���ò����Ů�ӣ��Բ�ͬ����̬
������������֮���������ԡ�ͼ��������һ�������������ء�
(dancing out)�롺�з����� ��
TEXT
]));

      set("objects", ([
          __DIR__"npc/girl" : 1 ]) );
	setup();
	replace_program(ROOM);
}