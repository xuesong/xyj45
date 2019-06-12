// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 

inherit NPC;

#include <quest_fd.h>
#include <quest_gv.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("祖冲之", ({"zu chongzhi", "zu", "chongzhi"}));
  set("long", "一位身披仙袍，面容严肃慈善的大数学家。\n");
  set("title", "大数学家");
  set("gender", "男性");
  set("age", 60);
  set("per", 40);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 5000000);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 200);
  set_skill("spells", 200);
  set("max_gin",3800);
  set("max_kee",3800);
  set("max_sen",3800);
  set("max_force",4000);
  set("max_mana",4000);
  set("force_factor",100);
  set("chat_chance",50);
  set("chat_msg",({
    "祖冲之说,小同志不要走,来来来,咱们切磋一下数学(mathematics)吧。\n",
  }));
  set("inquiry", ([
        "math":   (: test_player() :),
	  "mathematics":	(: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}

void rewarding (object who);


int test_player()
{
  object me = this_object();
  object who = this_player();
  int delay;
  int i, j;


    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，那咱们就先来15道题吧？\n",me,who);
	for(i=0;i<15;i++)
	{
  		write("你有" + CHINESE_D->chinese_number(skill_level) + "级的" + to_chinese(arg)
   		+ "，确定要放弃么？(y/n)\n");
  		input_to("confirm", arg, skill_level);
	}

  delay = MAXDELAY * i / sizeof(quest_keys) + 120 + uptime();


  if(!arg || sscanf(arg,"%d",value)!=1) {
  write("请输入"+giftn[index[ind]]+"的新取值[10-30]：");
  input_to("get_number",me,ind);
  return;
  }
  me->add_temp("gift_left",old_value-value);
  me->set_temp("gifts",gt);
  write("你将"+giftn[name]+"设为"+chinese_number(value)+"。\n");

  

  return 1;
}


void reward (object who)
{
  object me = this_object ();
  int points = who->query("quest/reward");
  object silver = new ("/obj/money/silver");
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  points = points * 10;
  message_vision ("$N对$n一拜：陛下有旨，赐"+RANK_D->query_respect(who)+
                  chinese_number(points)+"两白银！\n",me,who);
/*  
  command (channel+" "+who->query("name")+who->query("quest/reason")+"陛下有旨，赐"+
           chinese_number(points)+"两白银！\n");
*/  
  who->add("quest/gain/silver",points);
  reporting (who, who->query("quest/reason"), points, "两白银");
  
  silver->set_amount(points);
  if(!(silver->move(who)))
    silver->move(environment(who));
  message_vision ("$N递给$n一包白银。\n",me,who);
}

