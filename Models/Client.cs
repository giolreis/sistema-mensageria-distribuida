namespace Mensageria.Models;

public class Client
{
    public string Id { get; set; }
    public string Channel { get; set; }
    public LogicalClock Clock { get; set; } = new();

    public Client(string id, string channel)
    {
        Id = id;
        Channel = channel;
    }
}