use std::collections::VecDeque;

struct SnakeGame {
    width: i32,
    height: i32,
    food: Vec<Vec<i32>>,
    points: usize,
    snake: VecDeque<Point>,
}

struct Point {
    r: i32,
    c: i32,
}

impl Point {
    fn new(r: i32, c: i32) -> Self {
        Point {
            r: r,
            c: c,
        }
    }
}

impl PartialEq for Point {
    fn eq(&self, other: &Self) -> bool {
        self.r == other.r && self.c == other.c
    }
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SnakeGame {

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    fn new(width: i32, height: i32, food: Vec<Vec<i32>>) -> Self {
        let mut snake = VecDeque::with_capacity(food.len());
        snake.push_back(Point::new(0, 0));
        
        SnakeGame {
            width: width,
            height: height,
            food: food,
            points: 0,
            snake: snake,
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    fn make_a_move(&mut self, direction: String) -> i32 {
        let head = self.snake.front().unwrap();
        
        let new_head = match &direction[..] {
            "U" => Point::new(head.r - 1, head.c),
            "D" => Point::new(head.r + 1, head.c),
            "R" => Point::new(head.r, head.c + 1),
            "L" => Point::new(head.r, head.c - 1),
            _ => panic!(),
        };
        
        if self.snake.len() > self.points {
            self.snake.pop_back();
        }
        
        if new_head.r < 0 || new_head.r > self.height - 1 
            || new_head.c < 0 || new_head.c > self.width - 1
            || self.snake.contains(&new_head) {
                
            return -1;
        }
        
        if self.points < self.food.len()
            && new_head.r == self.food[self.points][0] 
            && new_head.c == self.food[self.points][1] {
                
            self.points += 1;
        }
        
        self.snake.push_front(new_head);
        
        self.points as i32
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * let obj = SnakeGame::new(width, height, food);
 * let ret_1: i32 = obj.make_a_move(direction);
 */
