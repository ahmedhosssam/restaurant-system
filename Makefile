CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp src/Manager.cpp src/Restaurant.cpp src/Stock.cpp src/Ingredient.cpp src/Menu.cpp src/Meal.cpp src/Order.cpp src/Delivery.cpp src/InRestaurant.cpp src/TakeAway.cpp src/Table.cpp src/general.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(TARGET)
	rm src/*.o
