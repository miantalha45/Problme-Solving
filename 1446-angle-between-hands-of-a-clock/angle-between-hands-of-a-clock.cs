public class Solution {
    public double AngleClock(int hour, int minutes) {
        double smallAngle = 0;
        double hourAngle = 0;
        double otherAngle = 0;
        if(hour == 12 && minutes == 00)
        {
            hourAngle = 0;
        }
        else{
            hourAngle = hour * 30 + minutes * 0.5;
        }

        double minuteAngle = minutes * 6;

        smallAngle = Math.Abs(hourAngle - minuteAngle);
        otherAngle = 360 - smallAngle;
        return smallAngle < otherAngle ? smallAngle : otherAngle;
    }
}