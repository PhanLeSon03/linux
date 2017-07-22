/*
 * ALSA SoC PCM5102a driver
 *
 *  This driver is used by controllers which can operate in DIT (SPDI/F) where
 *  no codec is needed.  This file provides stub codec that can be used
 *  in these configurations. TI DaVinci Audio controller uses this driver.
 *
 * Author:      Steve Chen,  <schen@mvista.com>
 * Copyright:   (C) 2009 MontaVista Software, Inc., <source@mvista.com>
 * Copyright:   (C) 2009  Texas Instruments, India
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <sound/soc.h>
#include <sound/pcm.h>
#include <sound/initval.h>
#include <linux/of.h>

#define DRV_NAME "pcm5102a"

#define STUB_RATES	SNDRV_PCM_RATE_8000_96000
#define STUB_FORMATS	(SNDRV_PCM_FMTBIT_S16_LE | \
			SNDRV_PCM_FMTBIT_S20_3LE | \
			SNDRV_PCM_FMTBIT_S24_LE| SNDRV_PCM_FMTBIT_S32_LE)


static struct snd_soc_codec_driver soc_codec_pcm5102a = {
};

static struct snd_soc_dai_driver pcm5102a_dai = {
	.name		= "pcm5102a-hifi",
	.playback 	= {
		.stream_name	= "Playback",
		.channels_min	= 1,
		.channels_max	= 2,
		.rates		= STUB_RATES,
		.formats	= STUB_FORMATS,
	},
};

static int pcm5102a_probe(struct platform_device *pdev)
{
        printk("PCM5102a probe...\n");
	return snd_soc_register_codec(&pdev->dev, &soc_codec_pcm5102a,
			&pcm5102a_dai, 1);
}

static int pcm5102a_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id pcm5102a_dt_ids[] = {
	{ .compatible = "linux,pcm5102a", },
	{ }
};
MODULE_DEVICE_TABLE(of, pcm5102a_dt_ids);
#endif

static struct platform_driver spdif_dit_driver = {
	.probe		= pcm5102a_probe,
	.remove		= pcm5102a_remove,
	.driver		= {
		.name	= DRV_NAME,
                .OWNER  = THIS_MODULE,
		.of_match_table = of_match_ptr(pcm5102a_dt_ids),
	},
};

module_platform_driver(pcm5102a_driver);

MODULE_AUTHOR("Steve Chen <schen@mvista.com>");
MODULE_DESCRIPTION("PCM5102A dummy codec driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRV_NAME);
