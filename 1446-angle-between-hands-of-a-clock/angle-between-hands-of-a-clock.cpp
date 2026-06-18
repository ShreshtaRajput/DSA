class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6;
        double hourAngle = (30 * hour) + (0.5 * minutes);

        double angle = abs(hourAngle - minuteAngle);

        return min(angle, 360 - angle);
    }
};