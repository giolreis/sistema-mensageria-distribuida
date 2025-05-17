using Mensageria.Models;
using Mensageria.Services;

var buffer = new MessageBuffer();

var client1 = new Client("Client1", "CanalA");
var client2 = new Client("Client2", "CanalA");
var client3 = new Client("Client3", "CanalB");

buffer.RegisterClient(client1);
buffer.RegisterClient(client2);
buffer.RegisterClient(client3);

buffer.SendMessage("Client1", "Olá Multicast", "CanalA", "multicast");
buffer.SendMessage("Client3", "Olá Broadcast", "N/A", "broadcast");