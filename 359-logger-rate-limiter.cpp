struct Record {
    int    timestamp;
    string message;
};

class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        optional<deque<Record>::const_iterator> erase_from;
        
        for (auto i = records.cbegin(); i != records.end(); i++) {
            if (i->timestamp + 10 <= timestamp) {
                erase_from = i;
                continue;
            }
            
            if (hash<string>()(message) == hash<string>()(i->message))
                return false;

            if (message == i->message)
                return false;
        }
        
        if (erase_from.has_value())
            records.erase(records.cbegin(), *erase_from);
        
        records.push_back((Record) { timestamp, std::move(message) });
        return true;
    }
    
private:
    deque<Record> records;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
