#include <stdio.h>
#include <string.h>

#define MAX_RIDES 50

// Structure for storing ride details
struct Ride
{
    int rideID;

    char name[50];
    char studentID[20];
    char phone[15];

    int source;
    int destination;

    char date[15];

    int hour;
    int minute;

    int seats;

    float fare;
};


// Array for storing rides
struct Ride rides[MAX_RIDES];

int rideCount = 0;


// Function to display locations
void showLocations()
{
    printf("\nChoose Location:\n");
    printf("1. UPES\n");
    printf("2. Prem Nagar\n");
    printf("3. ISBT\n");
    printf("4. Railway Station\n");
    printf("5. Dehradun\n");
}


// Function to display location name
void printLocation(int location)
{
    switch(location)
    {
        case 1:
            printf("UPES");
            break;

        case 2:
            printf("Prem Nagar");
            break;

        case 3:
            printf("ISBT");
            break;

        case 4:
            printf("Railway Station");
            break;

        case 5:
            printf("Dehradun");
            break;

        default:
            printf("Unknown");
    }
}


// Function for offering a ride
void offerRide()
{
    if(rideCount >= MAX_RIDES)
    {
        printf("\nRide storage is full!\n");
        return;
    }

    printf("\n=================================\n");
    printf("          OFFER A RIDE\n");
    printf("=================================\n");

    // Assign ride ID
    rides[rideCount].rideID = rideCount + 101;


    // Student details

    printf("Enter your name: ");
    scanf(" %[^\n]", rides[rideCount].name);

    printf("Enter Student ID: ");
    scanf("%s", rides[rideCount].studentID);

    printf("Enter Phone Number: ");
    scanf("%s", rides[rideCount].phone);


    // Source

    printf("\nSelect Source:");
    showLocations();

    printf("Enter choice: ");
    scanf("%d", &rides[rideCount].source);


    // Destination

    printf("\nSelect Destination:");
    showLocations();

    printf("Enter choice: ");
    scanf("%d", &rides[rideCount].destination);


    // Check same source and destination

    if(rides[rideCount].source ==
       rides[rideCount].destination)
    {
        printf("\nSource and destination cannot be same!\n");
        return;
    }


    // Date

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", rides[rideCount].date);


    // Time

    printf("Enter Hour (0-23): ");
    scanf("%d", &rides[rideCount].hour);

    printf("Enter Minutes (0-59): ");
    scanf("%d", &rides[rideCount].minute);


    // Seats

    printf("Enter Available Seats: ");
    scanf("%d", &rides[rideCount].seats);


    // Fare

    printf("Enter Total Fare: Rs. ");
    scanf("%f", &rides[rideCount].fare);


    printf("\n=================================\n");
    printf("     RIDE OFFERED SUCCESSFULLY\n");
    printf("=================================\n");

    printf("Ride ID: %d\n",
           rides[rideCount].rideID);

    printf("Route: ");

    printLocation(rides[rideCount].source);

    printf(" -> ");

    printLocation(rides[rideCount].destination);

    printf("\nDate: %s",
           rides[rideCount].date);

    printf("\nTime: %02d:%02d",
           rides[rideCount].hour,
           rides[rideCount].minute);

    printf("\nSeats Available: %d",
           rides[rideCount].seats);

    printf("\nTotal Fare: Rs. %.2f\n",
           rides[rideCount].fare);


    // Increase number of rides
    rideCount++;
}


// Function to display all rides
void viewRides()
{
    int i;

    if(rideCount == 0)
    {
        printf("\nNo rides available.\n");
        return;
    }


    printf("\n=================================\n");
    printf("        AVAILABLE RIDES\n");
    printf("=================================\n");


    for(i = 0; i < rideCount; i++)
    {
        if(rides[i].seats > 0)
        {
            printf("\nRide ID: %d\n",
                   rides[i].rideID);

            printf("Offered By: %s\n",
                   rides[i].name);

            printf("Route: ");

            printLocation(rides[i].source);

            printf(" -> ");

            printLocation(rides[i].destination);

            printf("\nDate: %s",
                   rides[i].date);

            printf("\nTime: %02d:%02d",
                   rides[i].hour,
                   rides[i].minute);

            printf("\nSeats: %d",
                   rides[i].seats);

            printf("\nFare: Rs. %.2f",
                   rides[i].fare);

            printf("\n-------------------------------\n");
        }
    }
}


// Function for finding a ride
void findRide()
{
    int source;
    int destination;

    char date[15];

    int i;
    int found = 0;

    int selectedRide;


    printf("\n=================================\n");
    printf("           FIND A RIDE\n");
    printf("=================================\n");


    // Select source

    printf("\nSelect Source:");
    showLocations();

    printf("Enter choice: ");
    scanf("%d", &source);


    // Select destination

    printf("\nSelect Destination:");
    showLocations();

    printf("Enter choice: ");
    scanf("%d", &destination);


    // Enter date

    printf("\nEnter Travel Date (DD/MM/YYYY): ");
    scanf("%s", date);


    printf("\nSearching for rides...\n");


    // Search all rides

    for(i = 0; i < rideCount; i++)
    {
        if(rides[i].source == source &&
           rides[i].destination == destination &&
           strcmp(rides[i].date, date) == 0 &&
           rides[i].seats > 0)
        {
            found = 1;


            printf("\n=================================\n");
            printf("           RIDE FOUND\n");
            printf("=================================\n");

            printf("Ride ID: %d\n",
                   rides[i].rideID);

            printf("Offered By: %s\n",
                   rides[i].name);

            printf("Route: ");

            printLocation(rides[i].source);

            printf(" -> ");

            printLocation(rides[i].destination);


            printf("\nDate: %s",
                   rides[i].date);

            printf("\nTime: %02d:%02d",
                   rides[i].hour,
                   rides[i].minute);

            printf("\nAvailable Seats: %d",
                   rides[i].seats);

            printf("\nTotal Fare: Rs. %.2f\n",
                   rides[i].fare);
        }
    }


    if(found == 0)
    {
        printf("\nNo matching rides found.\n");
        return;
    }


    // Booking

    printf("\nEnter Ride ID to book: ");
    scanf("%d", &selectedRide);


    for(i = 0; i < rideCount; i++)
    {
        if(rides[i].rideID == selectedRide &&
           rides[i].seats > 0)
        {
            rides[i].seats--;


            printf("\n=================================\n");
            printf("        BOOKING SUCCESSFUL\n");
            printf("=================================\n");

            printf("Ride Owner: %s\n",
                   rides[i].name);

            printf("Contact: %s\n",
                   rides[i].phone);

            printf("Remaining Seats: %d\n",
                   rides[i].seats);


            // Simple fare splitting

            printf("Estimated Fare Per Person: Rs. %.2f\n",
                   rides[i].fare /
                   (rides[i].seats + 2));

            return;
        }
    }


    printf("\nInvalid Ride ID!\n");
}


// Main function
int main()
{
    int choice;


    do
    {
        printf("\n=================================\n");
        printf("            RIDESYNC\n");
        printf("     Campus Carpool System\n");
        printf("=================================\n");

        printf("1. Offer a Ride\n");
        printf("2. Find a Ride\n");
        printf("3. View Available Rides\n");
        printf("4. Exit\n");

        printf("=================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1:
                offerRide();
                break;


            case 2:
                findRide();
                break;


            case 3:
                viewRides();
                break;


            case 4:
                printf("\nThank you for using RideSync!\n");
                break;


            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 4);


    return 0;
}