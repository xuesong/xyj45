// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ��̹ǵ��溮Ϯ�������е������ƶ������ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",
            environment(me), me);
   }
      me->receive_damage("kee", 25);
      me->receive_wound("gin", 10);
      me->apply_condition("xx_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}