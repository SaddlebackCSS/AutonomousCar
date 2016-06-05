/*
 */

#ifndef STEERING_H_
#define STEERING_H_
#include "GPIO.h"
#include "PWM.h"

namespace exploringBB
{
    /**
     * @class Steering
     * @brief A class to control steering of the front wheels
     */
    class Steering : public PWM {
    public:
            Steering();
            void steer(int percent);

            ~Steering();
    private:
        void init();
        const unsigned int RIGHT_MAX;
        const unsigned int LEFT_MAX;
        const unsigned int CENTER;
    };

} /* namespace exploringBB */

#endif /* STEERING_H_ */
