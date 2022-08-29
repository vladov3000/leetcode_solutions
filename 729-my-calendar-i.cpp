struct Booking {
    int start;
    int end;
};

bool earlier(const Booking& x, const Booking& y) {
    return x.start < y.start && x.end <= y.start;
}

class MyCalendar {
public:
    MyCalendar() : bookings(earlier) {
        
    }
    
    bool book(int start, int end) {
        Booking booking = { start, end };
        if (bookings.find(booking) != bookings.end())
            return false;
        
        bookings.insert(booking);
        return true;
    }

private:
    set<Booking, decltype(earlier)*> bookings;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
