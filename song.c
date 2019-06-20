// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit F_VENDOR_SALE;

void test_player();
int test_begin(object);
int math_test(object);
int reward_player(object);

void create()
{
   reload("song");
        set_name("������", ({"boss song", "song", "boss"}));
        set("title", "ˮ�����ϰ�");
        set("gender", "Ů��");
        set("age", 35);
        set("long",
"������һ�ź��������ϰ壬ʵ�����Ǹ�������֯����֯�ߡ������˵��ʲô�и���ϣ\n");
        set("kee", 3000); 
        set("max_kee", 3000);
        set("sen", 2000);
        set("max_sen", 2000);
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("inquiry", ([
                "english": (: test_player :),
        ]) );

        set("vendor_goods", ([
     		"strawberry": "/d/obj/food/strawberry",
			"grape": "/d/obj/food/grape",
			"pear": "/d/obj/food/xueli",
			"bailangua": "/d/qujing/tianzhu/obj/bailangua",
			"papaya": "/d/qujing/tianzhu/obj/mugua",
			"papaya": "/d/qujing/tianzhu/obj/fanmugua",
			"orange": "/d/qujing/tianzhu/obj/juzi",
			"grapefruit": "/d/qujing/tianzhu/obj/youzi",

        ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 300);
        set_skill("dodge", 600);

        setup();
        carry_object("/d/obj/cloth/nichang")->wear();
}


void test_player()
{
  object me = this_object();
  object who = this_player();


    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������ǾͿ�ʼ��\n",me,who);
    write ("����ʱ10�뿪ʼ.\n");

	math_test(who);
}

int math_test(object who)
{
    call_out("exam_end",100,who);
    who->set_temp("correct_count", 0);
    who->set_temp("total_count", 0);
    who->set_temp("test_end",0);
    
	test_begin(who);

}

int test_begin(object who)
{
	int tt;
	int x,y,z;
	if ((who->query_temp("total_count")>14) || who->query_temp("test_end"))
	{
		reward_player(who);
		return 1;
	}

	tt = random(5);

	switch ( tt ) {
		case 0:
			x = random(99) + 1;
			y = random(99) + 1;
			z = x+y;
			write (sprintf(" %d + %d = ",x,y));

			break;
		case 1:
			x = random(101);
			z = 100 - x;
			write (sprintf(" 100 - %d = ",x));
			break;
		case 2:
			x = random(8) + 2;
			z = x*x*x;
			write (sprintf(" %d x %d x %d = ",x,x,x));

			break;
		case 3:
			x = 11 + random(9);
			z = x*x;
			write (sprintf(" %d x %d = ",x,x));

			break;
		case 4:
			x = 1 + random(11);
			if (x == 10) {
				x = 16;
			} else if (x == 11) {
				x = 25;
			}
			z = x*314;
			write (sprintf(" %d x 314 = ",x));
			break;
		}
		
		who->add_temp("total_count", 1);
		input_to("check_result",who,z);
		
}  

int reward_player(object who)
{
	int tt; //test type
	int cc = 0; // correct count
	object silver = new ("/obj/money/silver");
	object me = this_object();
	
	remove_call_out("exam_end");
	write(sprintf("������ %d ��\n",who->query_temp("correct_count")));

	cc = who->query_temp("correct_count");
	if(cc == 15)
		tt = cc + 500;
	else if (cc == 0 )
		return 0;
	else
		tt = cc*5;

	silver->set_amount(tt);
	if(!(silver->move(who)))
	  silver->move(environment(who));
	message_vision ("$N�ݸ�$nһ��������\n",me,who);


	command("chat " + "��ϲ"+ who->query("name") + "���"+chinese_number(cc)+"����ѧ�⣬�õ���"+chinese_number(tt)+"����������!");

	who->delete_temp("answer_result");
	who->delete_temp("total_count");
	who->delete_temp("test_end");
  return 1;
}

int check_result(string as,object who, int gas )
{
	int value;
	string raw;
	int z;
	if(sscanf(as,"%d",value)){
		if (value == gas){
			who->add_temp("correct_count", 1);
			write("Bingo!\n");
		} else {
			write(sprintf("��ȷ���� %d ,�����Ŭ��\n",gas));
		}
	}
	
	test_begin(who);
	return 1;
}

void exam_end(object who,int i)
{
	remove_call_out("exam_end");

	who->set_temp("test_end",1);
}






void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

