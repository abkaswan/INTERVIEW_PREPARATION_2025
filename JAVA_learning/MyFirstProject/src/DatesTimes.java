import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class DatesTimes {
    public void play(){
        // How to work with Dates & Times using java
        // (LocalDate, LocalTime, LocalDateTime, UTC Timestamp)

        LocalDate date = LocalDate.now();
        System.out.println(date);

        LocalTime time = LocalTime.now();
        System.out.println(time);

        LocalDateTime localDateTime = LocalDateTime.now();
        System.out.println(localDateTime);

        // UTC time
        Instant instant = Instant.now();
        System.out.println(instant);

        // custom format -- let's do for localDateTime
        System.out.println("_____________ CUSTOM FORMAT _____________");
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        String newDateTime = localDateTime.format(formatter);
        System.out.println(newDateTime);

        System.out.println("_____________ CUSTOM Date time Object instead of today _____________");
        LocalDate customDate = LocalDate.of(2024,12,25);
        System.out.println(customDate);

        LocalDateTime customDateTime = LocalDateTime.of(2024,12,25,12,0,0);
        System.out.println(customDateTime);

        // compare dates
        LocalDateTime customDateTime1 = LocalDateTime.of(2025,1,2,12,0,0);
        LocalDateTime customDateTime2 = LocalDateTime.of(2025,1,1,0,0,0);
        if(customDateTime1.isBefore(customDateTime2))
        {
            System.out.println(customDateTime1+" is earlier than "+customDateTime2);
        }
        else if(customDateTime1.isAfter(customDateTime2)){
            System.out.println(customDateTime1+" is later than "+customDateTime2);
        }
        else if(customDateTime1.isEqual(customDateTime2)){
            System.out.println(customDateTime1+" is equal to "+customDateTime2);
        }
    }
}
