namespace Mensageria.Models;

public class LogicalClock
{
    private int time = 0;

    public int Tick()
    {
        return ++time;
    }

    public int Update(int receivedTime)
    {
        time = Math.Max(time, receivedTime) + 1;
        return time;
    }

    public int Current => time;
}



