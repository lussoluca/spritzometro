void FlowAperolCount()
{
  if (flowMilliLitres <= 40) {
    digitalWrite(Pump2, HIGH);
    digitalWrite(Valve2, HIGH);
  }
  else {
    digitalWrite(Pump2, LOW);
    digitalWrite(Valve2, LOW);
  }
}
