class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        if (minutes == 60) minutes = 0;

        double hourAngle = (hour * 30) + (0.5 * minutes);
        double minuteAngle = 6 * minutes;

        double angle = abs(minuteAngle - hourAngle);

        return min(angle, 360 - angle);
    }
};