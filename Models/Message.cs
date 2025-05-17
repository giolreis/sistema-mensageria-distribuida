namespace Mensageria.Models
{
    public class Message
    {
        public string Content { get; set; }
        public string ProducerId { get; set; }
        public string ConsumerId { get; set; } = "N/A";
        public int SentTimestamp { get; set; }
        public int ReceivedTimestamp { get; set; } = -1;
        public string Channel { get; set; }
    }
}

