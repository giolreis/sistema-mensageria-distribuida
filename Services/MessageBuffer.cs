namespace Mensageria.Services;
using System.Collections.Generic;
using Mensageria.Models;

public class MessageBuffer
{
    private readonly List<Client> clients = new();
    private readonly List<Message> buffer = new();

    public void RegisterClient(Client client)
    {
        clients.Add(client);
    }

    public void SendMessage(string producerId, string content, string channel, string mode)
    {
        var clock = clients.First(c => c.Id == producerId).Clock;
        int timestamp = clock.Tick();

        var message = new Message
        {
            ProducerId = producerId,
            Content = content,
            SentTimestamp = timestamp,
            Channel = channel
        };

        buffer.Add(message);
        LogSend(message);

        switch (mode)
        {
            case "unicast":
                DeliverMessage(message, clients.FirstOrDefault(c => c.Channel == channel));
                break;
            case "multicast":
                foreach (var client in clients.Where(c => c.Channel == channel))
                    DeliverMessage(message, client);
                break;
            case "broadcast":
                foreach (var client in clients)
                    DeliverMessage(message, client);
                break;
        }
    }

    private void DeliverMessage(Message message, Client client)
    {
        if (client == null) return;

        message.ReceivedTimestamp = client.Clock.Update(message.SentTimestamp);
        message.ConsumerId = client.Id;
        LogReceive(message);
    }

    private void LogSend(Message msg)
    {
        File.AppendAllText("Logs/SendLog.txt", $"[SEND] {msg.ProducerId} @ {msg.SentTimestamp}: {msg.Content} ({msg.Channel})\n");
    }

    private void LogReceive(Message msg)
    {
        File.AppendAllText("Logs/ReceiveLog.txt", $"[RECV] {msg.ConsumerId} @ {msg.ReceivedTimestamp}: {msg.Content} (from {msg.ProducerId})\n");
    }
}