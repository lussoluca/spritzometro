void FlowSodaCount()
{
  if (flowMilliLitres <= 20) {
    digitalWrite(Pump3, HIGH);
    digitalWrite(Valve3, HIGH);
  }
  else {
    digitalWrite(Pump3, LOW);
    digitalWrite(Valve3, LOW);
  }
}
