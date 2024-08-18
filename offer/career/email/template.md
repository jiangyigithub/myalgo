can you see my screen?

Q:
```md
Dear Yi:
How are you doing? It’s been a while, I hope you are good and projects are still interesting!

We now took a couple of radar measurements in the infrastructure. I want to analyze whether interferences between multiple Radars happen.

To that aim, within Radar DSP level, there is an algorithm called “Interference indicator”. The output are the below signals
    IntfrIndcr
    IntfrIndcrStatus

Which unfortunately are constantly 0, which means “not computed”

Do you have any knowledge on that area? How can we switch on computation of the interference indicator?

If this is new to you – who can I ask?

Thank you in advance!

Joachim
```

A:
```
For the topic you mentioned in the last e-mail, I check the interference signals in other project, some information can be shared with you:

    Signal name:” _g_Dsp_dsp_dsp_m_LocationInterface_out_local.TChangeableMemPool._._._m_arrayPool._0_._elem._m_SensState._Interference_st._IntfrIndcrStatus” can be used for interference status indicator, you can search for this signal if it exists. I think this signal has the same meaning as the signal you show in the picture. Also if the value is 1, means interference is happened. If the value is 0, means no interference and “not computed”

    The interference calculation will be run in the DSP module, and it will be detected the interference during the radar working time.

    For the interference test, you can try to set an iron plate in front of the two radars, the iron plate should cover the two radars’ FoV. Then you will find the signal value jumps between 0 and 1.
```