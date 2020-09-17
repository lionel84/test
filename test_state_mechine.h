/*
 * @Auth: lionelzhang
 * @Date: 2020-09-07 10:41:03
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-09-07 11:06:13
 * @Description: 
 */
namespace nm_state_mechine {
    enum STATE{
        STATE_0 = 1,
        STATE_1,
        STATE_2,
        STATE_FINI
    };
    class STATEMECHINE{
        public:
        STATEMECHINE():m_curState(STATE_0) {}
        ~STATEMECHINE(){}

        public:
        int32_t doAction(){
            switch (m_curState)
            {
            case STATE_0:
                // do something
                printf("now is STATE_0 next is STATE_1\n");
                ChangeState(STATE_1);
                break;
            case STATE_1:
                // do something
                printf("now is STATE_1 next is STATE_2\n");
                ChangeState(STATE_2);
                break;
            case STATE_2:
                // do something
                printf("now is STATE_2 next is STATE_FINI\n");
                ChangeState(STATE_FINI);
                break;
            case STATE_FINI:
                // do something
                printf("now is STATE_3 finished\n");
                break;
            default:

                break;
            }
        }
        int32_t ChangeState(STATE nState){
            m_curState = nState;
            //doAction();
        }

        void loop()
        {
            doAction();
        }
        inline bool is_fini(){
            return m_curState == STATE_FINI;
        }
        private:
            STATE m_curState;

    };
}