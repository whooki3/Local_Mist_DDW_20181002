String convertSex(int s) {

  switch (s) {
    case 0:
      return "Heterosexual";
      break;
    case 1:
      return "Homosexual";
      break;
    default:
      return "Apache";
      break;
  }

}


String convertEth(int s) {
  switch (s) {
    case 0:
      return "White";
      break;
    case 1:
      return "Black";
      break;
    default:
      return "Other";
      break;
  }

}


String getWeekday(int w) {
  switch (w) {
    case 0:
      return "MON";
      break;
    case 1:
      return "TUE";
      break;
    case 2:
      return "WED";
      break;
    case 3:
      return "THU";
      break;
    case 4:
      return "FRI";
      break;
    case 5:
      return "SAT";
      break;
    case 6:
      return "SAT";
      break;
  }
}

String getMonth(int m) {
  switch (m) {
    case 1:
      return "JAN";
      break;
    case 2:
      return "FEB";
      break;
    case 3:
      return "MAR";
      break;
    case 4:
      return "APR";
      break;
    case 5:
      return "MAY";
      break;
    case 6:
      return "JUN";
      break;
    case 7:
      return "JUL";
      break;
    case 8:
      return "AUG";
      break;
    case 9:
      return "SEPT";
      break;
    case 10:
      return "OCT";
      break;
    case 11:
      return "NOV";
      break;
    case 12:
      return "DEC";
      break;
  }
}
