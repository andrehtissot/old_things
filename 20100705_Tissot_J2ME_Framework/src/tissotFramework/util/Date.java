package tissotFramework.util;

import java.util.Calendar;

/** @author André Tissot */
public class Date extends java.util.Date {
    public Date() {
        super();
    }
    public Date(long date) {
        super(date);
    }
    public Date(String timestamp) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.YEAR, Integer.parseInt(timestamp.substring(0, 4)));
        calendar.set(Calendar.DAY_OF_MONTH, Integer.parseInt(timestamp.substring(8, 10)));
        calendar.set(Calendar.MONTH, Integer.parseInt(timestamp.substring(5, 7)) - 1);
        calendar.set(Calendar.HOUR_OF_DAY, Integer.parseInt(timestamp.substring(11, 13)));
        calendar.set(Calendar.MINUTE, Integer.parseInt(timestamp.substring(14, 16)));
        calendar.set(Calendar.SECOND, Integer.parseInt(timestamp.substring(17, 19)));
        this.setTime(calendar.getTime().getTime());
    }
    public static long daysOfDifference(Date date1, Date date2) {
        if (date1.getTime() > date2.getTime()) {
            return ((date1.getTime() - date2.getTime()) / 86400000);
        } else {
            return ((date2.getTime() - date1.getTime()) / 86400000);
        }
    }
    public long numberOfWeek(Date dayZero) {
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(dayZero);
        return (daysOfDifference(dayZero, this) + calendar.get(Calendar.DAY_OF_WEEK) - 1) / 7;
    }
    public static Date firstDayOfTheWeek(Date dayZero, long weekNumber) {
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(dayZero);
        return new Date(dayZero.getTime() + (weekNumber * 604800000) - ((calendar.get(Calendar.DAY_OF_WEEK) - 1) * 86400000));
    }
    public static Date lastDayOfTheWeek(Date firstDay, long weekNumber) {
        return new Date(firstDayOfTheWeek(firstDay, weekNumber).getTime() + 518400000);
    }
    public String toTimestamp() {
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(this);

        String hour = String.valueOf(calendar.get(Calendar.HOUR_OF_DAY));
        if (hour.length() < 2) {
            hour = "0" + hour;
        }
        String minute = String.valueOf(calendar.get(Calendar.MINUTE));
        if (minute.length() < 2) {
            minute = "0" + minute;
        }
        String second = String.valueOf(calendar.get(Calendar.SECOND));
        if (second.length() < 2) {
            second = "0" + second;
        }
        String year = String.valueOf(calendar.get(Calendar.YEAR));
        String month = String.valueOf(calendar.get(Calendar.MONTH) + 1);
        if (month.length() < 2) {
            month = "0" + month;
        }
        String day = String.valueOf(calendar.get(Calendar.DAY_OF_MONTH));
        if (day.length() < 2) {
            day = "0" + day;
        }
        return year + "-" + month + "-" + day + " " + hour + ":" + minute + ":" + second;
    }
    public int toIntYMD(){
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(this);
        String year = String.valueOf(calendar.get(Calendar.YEAR));
        String month = String.valueOf(calendar.get(Calendar.MONTH) + 1);
        if (month.length() < 2) {
            month = "0" + month;
        }
        String day = String.valueOf(calendar.get(Calendar.DAY_OF_MONTH));
        if (day.length() < 2) {
            day = "0" + day;
        }
        return Integer.parseInt(year + month + day);
    }
    public String brazilianFormat(){
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(this);
        String hour = String.valueOf(calendar.get(Calendar.HOUR_OF_DAY));
        if (hour.length() < 2) {
            hour = "0" + hour;
        }
        String minute = String.valueOf(calendar.get(Calendar.MINUTE));
        if (minute.length() < 2) {
            minute = "0" + minute;
        }
        String second = String.valueOf(calendar.get(Calendar.SECOND));
        if (second.length() < 2) {
            second = "0" + second;
        }
        String year = String.valueOf(calendar.get(Calendar.YEAR));
        String month = String.valueOf(calendar.get(Calendar.MONTH) + 1);
        if (month.length() < 2) {
            month = "0" + month;
        }
        String day = String.valueOf(calendar.get(Calendar.DAY_OF_MONTH));
        if (day.length() < 2) {
            day = "0" + day;
        }
        return day + "/" + month + "/" + year + " " + hour + ":" + minute + ":" + second;
    }
    public String brazilianFormatYMD(){
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(this);
        String year = String.valueOf(calendar.get(Calendar.YEAR));
        String month = String.valueOf(calendar.get(Calendar.MONTH) + 1);
        if (month.length() < 2) {
            month = "0" + month;
        }
        String day = String.valueOf(calendar.get(Calendar.DAY_OF_MONTH));
        if (day.length() < 2) {
            day = "0" + day;
        }
        return day + "/" + month + "/" + year;
    }
    public String brazilianFormatHMS(){
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(this);
        String hour = String.valueOf(calendar.get(Calendar.HOUR_OF_DAY));
        if (hour.length() < 2) {
            hour = "0" + hour;
        }
        String minute = String.valueOf(calendar.get(Calendar.MINUTE));
        if (minute.length() < 2) {
            minute = "0" + minute;
        }
        String second = String.valueOf(calendar.get(Calendar.SECOND));
        if (second.length() < 2) {
            second = "0" + second;
        }
        return hour + ":" + minute + ":" + second;
    }
}
