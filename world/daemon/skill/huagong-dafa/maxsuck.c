// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// maxsuck.c

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	my_max = me->query("max_force");
	tg_max = target->query("max_force");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ����Ԫ��\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�û��������˵�Ԫ��\n");

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("�������ս���в�����ȡ�Է��ĵ�Ԫ��\n");

	if( (int)me->query_skill("huagong-dafa",1) < 90 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է��ĵ�Ԫ���\n");

	if( (int)me->query("force",1) < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("max_force") < 100 )
		return notify_fail( target->name() +
			"��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		return notify_fail( target->name() +
			"���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

	message_vision(
		HIR "$Nȫ���ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

	me->set_temp("sucked", 1);		

	if( random(sp) > random(dp) ) 
	{
		tell_object(target, HIR "��ֻ���춥���ѣ�ȫ���������Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);

		target->add("max_force",  -1*(1+(me->query_skill("huagong-dafa", 1)-90)/10) );
		me->add("max_force",       1*(1+(me->query_skill("huagong-dafa", 1)-90)/10) );

		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
			me->add("potential",  10);
		me->add("combat_exp", 10);

		me->start_busy(random(10));
		target->start_busy(random(10));
		me->add("force", -20);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->start_busy(10);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
