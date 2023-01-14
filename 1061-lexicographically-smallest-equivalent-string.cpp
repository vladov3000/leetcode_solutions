class Equivalence {
public:
    Equivalence() noexcept : inner() {}
    void set_equal(char x, char y) noexcept;
    unsigned char parent(char element) noexcept;

private:
    unsigned char inner[CHAR_MAX];
};

void Equivalence::set_equal(char x, char y) noexcept {
    unsigned char parent_x = parent(x);
    unsigned char parent_y = parent(y);

    if (parent_x == parent_y)
        return;
    else if (parent_x < parent_y)
        inner[parent_y] = parent_x;
    else // parent_x > parent_y
        inner[parent_x] = parent_y;
}

unsigned char Equivalence::parent(char element) noexcept {
    unsigned char result = element;
    while (inner[result])
        result = inner[result];
    if (element != result)
        inner[element] = result;
    return result;
} 

class Solution {
public:
    string smallestEquivalentString(const string& s1, 
                                    const string& s2, 
                                    const string& base) {
        Equivalence equivalence;
        for (int i = 0; i < s1.size(); i++)
            equivalence.set_equal(s1[i], s2[i]);

        string result(base);
        for (int i = 0; i < base.size(); i++)
            result[i] = equivalence.parent(base[i]);

        return result;
    }
};
