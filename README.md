# BombTrigger_UE
A bomb with player detection and time counter. When player step into the detect zone it will trigger the bomb counter and explode the object after counter count down to zero.

 The make it works you have to set up the followings :
- Set up “DetectRadius” in details panel to decide the detection range of bomb counter
- Set up “CountDownSeconds” in details panel to decide how long should we count down from
- Attach a mesh in details panel’s “KeyObject” slot. This will be the mesh of the bomb
- Add an explosion partical effect in “ExplosionParticle” slot as this will be trigger after the bomb counter reach zero

 
![BombTrigger](https://github.com/TimChen1383/BombTrigger_UE/assets/37008451/d6edfc3e-6762-4ff2-95ae-65a071de4d04)
